/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions load
*/
#include <stdbool.h>
#include "define.h"
#include "struct.h"
#include "utils.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

bool load_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int reg_id = (unsigned int)args[1]->arg[0];
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;
    unsigned char *to_load = get_arg_content(args[0], robot_id,
        (main_t *)value);

    for (unsigned int i = 0; i < REG_SIZE; i++)
        infos->regs[reg_id][i] = to_load[i];
    set_carry_null_reg(infos->regs[reg_id], infos);
    free(to_load);
    return true;
}

bool load_ind_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;
    unsigned int arg_a = get_u_arg_content(args[0], robot_id, (main_t *)value);
    unsigned int arg_b = get_u_arg_content(args[1], robot_id, (main_t *)value);
    unsigned int reg_id = (unsigned int)args[2]->arg[0];
    unsigned int source = (infos->pc + (arg_a + arg_b) % IDX_MOD) % MEM_SIZE;

    for (unsigned int i = 0; i < REG_SIZE; i++)
        infos->regs[reg_id][i] = ((main_t *)value)->arena[(source + i) %
            MEM_SIZE];
    set_carry_null_reg(infos->regs[reg_id], infos);
    return true;
}

bool load_long_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;
    unsigned int source = get_u_arg_content(args[0], robot_id, (main_t *)value);
    unsigned int dest = (unsigned int)args[1]->arg[0];

    source = (infos->pc + source) % MEM_SIZE;
    for (unsigned int i = 0; i < REG_SIZE; i++)
        infos->regs[dest][i] = ((main_t *)value)->arena[(source + i) %
            MEM_SIZE];
    set_carry_null_reg(infos->regs[dest], infos);
    return true;
}

bool load_long_ind_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;
    unsigned int arg_a = get_u_arg_content(args[0], robot_id, (main_t *)value);
    unsigned int arg_b = get_u_arg_content(args[1], robot_id, (main_t *)value);
    unsigned int reg_id = (unsigned int)args[2]->arg[0];
    unsigned int source = (infos->pc + (arg_a + arg_b)) % MEM_SIZE;

    for (unsigned int i = 0; i < REG_SIZE; i++)
        infos->regs[reg_id][i] = ((main_t *)value)->arena[(source + i) %
            MEM_SIZE];
    set_carry_null_reg(infos->regs[reg_id], infos);
    return true;
}
