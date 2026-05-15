/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "op.h"
#include "define.h"
#include "struct.h"
#include "utils.h"
#include "game.h"

static unsigned int get_instr_mem_size(main_t *main, unsigned int **args_tab,
    unsigned int pos_start, unsigned int *nbr_args)
{
    unsigned char id_instr = main->arena[pos_start];

    if (id_instr <= 0 || id_instr > NB_INSTR)
        return 0;
    if (op_tab[id_instr].coding_byte){
        *args_tab = get_coding_byte_tab(
            main->arena[(pos_start + 1) % MEM_SIZE], id_instr);
        if (!*args_tab)
            return 0;
        return get_global_size(*args_tab, nbr_args) + 2;
    } else {
        *nbr_args = 1;
        return get_size_from_id(id_instr) + 1;
    }
}

static unsigned char *build_instr_mem(main_t *main,
    robot_game_infos_t *infos, unsigned int size, unsigned int nbr_args)
{
    unsigned int pos_start = infos->pc % MEM_SIZE;
    unsigned char *instr = NULL;

    if (main->arena[pos_start] <= 0 || main->arena[pos_start] > NB_INSTR
        || nbr_args != op_tab[main->arena[pos_start]].nbr_args)
        return NULL;
    instr = my_ustrndup(main->arena, pos_start, pos_start + size);
    if (!instr)
        return NULL;
    return instr;
}

static unsigned char *get_instr_mem(main_t *main, unsigned int robot_id,
    unsigned int *size)
{
    robot_game_infos_t *infos = main->robots[robot_id].game_infos;
    unsigned int *args_tab = NULL;
    unsigned int nbr_args = 0;
    unsigned char *instr = NULL;

    *size = get_instr_mem_size(main, &args_tab,
        infos->pc % MEM_SIZE, &nbr_args);
    if (!*size)
        return NULL;
    instr = build_instr_mem(main, infos, *size, nbr_args);
    if (args_tab)
        free(args_tab);
    return instr;
}

static bool decrement_robot_cycle(robot_infos_t *robot, unsigned int id)
{
    if (robot->game_infos->cycles_remaining){
        robot->game_infos->cycles_remaining--;
        return true;
    }
    return false;
}

static bool apply_instr(main_t *main, instr_t *instr,
    unsigned int robot_id)
{
    return op_tab[instr->id].instr_func(main, instr->args,
        robot_id);
}

static bool translate_and_apply(unsigned char *instr,
    main_t *main, unsigned int index)
{
    instr_t *args = translate_mem(instr);

    if (!args || !apply_instr(main, args, index)){
        free_instr(args);
        return false;
    }
    main->robots[index].game_infos->cycles_remaining =
        op_tab[args->id].nbr_cycles;
    free_instr(args);
    return true;
}

static bool apply_robot_instr(main_t *main, unsigned int index,
    robot_infos_t *robot)
{
    unsigned char *instr = NULL;
    unsigned int size = 0;
    unsigned int pc_start = 0;

    if (robot->child)
        apply_robot_instr(main, index, robot->child);
    if (decrement_robot_cycle(robot, index))
        return true;
    pc_start = main->robots[index].game_infos->pc % MEM_SIZE;
    instr = get_instr_mem(main, index, &size);
    if (!instr){
        robot->game_infos->pc = (robot->game_infos->pc + 1) % MEM_SIZE;
        return true;
    }
    if (!translate_and_apply(instr, main, index)){
        free(instr);
        return false;
    }
    free(instr);
    if (robot->game_infos->pc % MEM_SIZE == pc_start)
        robot->game_infos->pc = (pc_start + size) % MEM_SIZE;
    return true;
}

bool apply_cycle(main_t *main)
{
    unsigned int size = 0;

    for (unsigned int i = 0; i < main->nbr_robots; i++)
        if (main->robots[i].game_infos->alive
            && !apply_robot_instr(main, i, &(main->robots[i])))
            return false;
    return true;
}
