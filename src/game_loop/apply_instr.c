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

static unsigned char *get_instr_mem(main_t *main, unsigned int robot_id)
{
    int pos_start = 0;
    unsigned char *instr = NULL;
    unsigned int size = 0;
    unsigned int *args_tab = NULL;
    unsigned int nbr_args = 0;

    printf("pos start: %i\n", main->robots[robot_id].pos_infos->pos_next_instr);
    pos_start = main->robots[robot_id].pos_infos->pos_next_instr;
    if (op_tab[main->arena[pos_start]].coding_byte){
        args_tab = get_coding_byte_tab(main->arena[pos_start + 1], main->arena[pos_start]);
        if (!args_tab)
            return put_error("incorrect coding byte tab in get_instr_mem", NULL);
        size = get_global_size(args_tab, &nbr_args) + 2;
        printf("has_bytecode\n");
    } else {
        size = get_size_from_id(main->arena[pos_start]) + 1;
        nbr_args = 1;
    }
    printf("size: %i\n", size);
    printf("id instr: %i\n", main->arena[pos_start]);
    printf("nbr_args: %i\n", nbr_args);
    printf("nbr_args_actual: %i\n", op_tab[main->arena[pos_start]].nbr_args);
    if (main->arena[pos_start] <= 0 || main->arena[pos_start] > NB_INSTR
        || nbr_args != op_tab[main->arena[pos_start]].nbr_args)
        return NULL;
    instr = my_ustrndup(main->arena, pos_start, pos_start + size);
    if (!instr)
        return put_error("Error: dup in apply_instructions.\n", NULL);
    main->robots[robot_id].pos_infos->pos_next_instr += size;
    //free_values((void **){(void *)args_tab}, 1);
    return instr;
}

static bool decrement_robot_cycle(main_t *main, unsigned int id)
{
    if (main->robots[id].game_infos->cycles_remaining){
        main->robots[id].game_infos->cycles_remaining--;
        return true;
    }
    return false;
}

static bool apply_instr(main_t *main, instr_t *instr,
    unsigned int robot_id)
{
    printf("id in apply: %i\n", instr->id);
    return op_tab[instr->id].instr_func(main, instr->args,
        robot_id);
}

static bool translate_and_apply(instr_t *args, unsigned char *instr,
    main_t *main, unsigned int index)
{
    args = translate_mem(instr);
    if (!args || !apply_instr(main, args, index)){
        free_instr(args);
        return put_error("incorrects args or apply_instr failed", false);
    }
    main->robots[index].game_infos->cycles_remaining 
    = op_tab[args->id].nbr_cycles;
    free_values((void *[5]){(void *)instr, (void *)(&(args->args[0])),
        (void *)(&(args->args[1])), (void *)(&(args->args[2])), (void *)args}, 5);
    return true;
}

bool apply_robot_instr(main_t *main, unsigned int index, robot_infos_t *robot)
{
    unsigned char *instr = NULL;
    instr_t *args = NULL;

    if (decrement_robot_cycle(main, index))
        return true;
    if (robot->pos_infos->pos_next_instr > robot->pos_infos->pos_end)
        robot->pos_infos->pos_next_instr = robot->pos_infos->pos_start;
    instr = get_instr_mem(main, index);
    if (!instr){
        printf("failed\n");
        free_values((void *[2]){(void *)instr, (void *)args}, 2);
        robot->pos_infos->pos_next_instr++;
        return true;
    }
    if (!translate_and_apply(args, instr, main, index))
        return false;
    if (robot->child)
        return apply_robot_instr(main, index, robot->child);
    return true;
}

bool apply_cycle(main_t *main)
{
    unsigned int size = 0;

    for (unsigned int i = 0; i < main->nbr_robots; i++)
        if (!apply_robot_instr(main, i, &(main->robots[i])))
            return false;
    return true;
}
