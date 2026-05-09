/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions basic
*/

#include <stdbool.h>
#include "op_define.h"
#include "struct.h"

bool live_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int start = ((main_t *)value)->robots[(int)(args[0]->arg[0])]
        .pos_infos->pos_next_instr;
    unsigned int end = ((main_t *)value)->robots[(int)(args[0]->arg[0])]
        .pos_infos->pos_end;

    if (start > end)
        return false;
    return true;
}

bool add_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    return true;
}

bool sub_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    return true;
}

bool print_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    return true;
}

bool jump_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    return true;
}
