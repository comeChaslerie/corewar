/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions load
*/
#include <stdbool.h>
#include "op_define.h"
#include "struct.h"
#include "hexa_calc.h"

bool load_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int source = uctoui(args[0]->arg, args[0]->type);
    unsigned int reg_id = (unsigned int)args[1]->arg[0];
    main_t *main = (main_t *)value;
    unsigned char **regs = main->robots[robot_id].game_infos->regs;

    source += main->robots[robot_id].pos_infos->pos_next_instr;
    for (unsigned int i = 0; i < REG_SIZE; i++)
        regs[reg_id][i] = main->arena[source + i];
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
