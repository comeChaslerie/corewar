/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdlib.h>
#include <stdbool.h>
#include "op.h"
#include "struct.h"
#include "utils.h"
#include "game.h"

static unsigned char *get_instr_mem(main_t *main, unsigned int id)
{
    int pos_start = 0;
    unsigned char *instr = NULL;
    unsigned int size = 0;
    unsigned int *args_size = NULL;
    unsigned int nbr_args = 0;

    pos_start = main->robots[id].pos_infos->pos_start;
    args_size = get_coding_byte_tab(main->arena[pos_start + 1], id);
    if (!args_size)
        return NULL;
    size = get_global_size(args_size, &nbr_args);
    if (nbr_args != op_tab[main->arena[pos_start + 1]].nbr_args)
        return false;
    instr = my_ustrndup(main->arena, pos_start, pos_start + size);
    if (!instr)
        return put_error("Error: dup in apply_instructions.\n", NULL);
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
    return op_tab[instr->id].instr_func(main, instr->args,
        robot_id);
}

bool apply_instructions(main_t *main)
{
    unsigned int size = 0;
    unsigned char *instr = NULL;
    instr_t *args = NULL;

    for (unsigned int i = 0; i < main->nbr_robots; i++){
        if (decrement_robot_cycle(main, i))
            continue;
        instr = get_instr_mem(main, i);
        if (!instr)
            return false;
        args = translate_mem(instr);
        if (!args || !apply_instr(main, args, i))
            return false;
        main->robots[i].game_infos->cycles_remaining
        = op_tab[args->id].nbr_cycles;
        free(instr);
        free(args);
    }
    return true;
}
