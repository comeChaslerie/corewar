/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions load
*/
#include <stdbool.h>
#include "define.h"
#include "struct.h"
#include "hexa_calc.h"
#include "utils.h"

bool load_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int source = uctoui(args[0]->arg, args[0]->type);
    unsigned int reg_id = (unsigned int)args[1]->arg[0];
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;

    source += ((main_t *)value)->robots[robot_id].pos_infos->pos_next_instr;
    for (unsigned int i = 0; i < REG_SIZE; i++)
        infos->regs[reg_id][i] = ((main_t *)value)->arena[source + i];
    set_carry_null_reg(infos->regs[reg_id], infos);
    return true;
}

bool load_ind_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    return true;
}

bool load_long_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    return true;
}

bool load_long_ind_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    return true;
}
