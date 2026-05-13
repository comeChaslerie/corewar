/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions load
*/
#include <stdbool.h>
#include <stdlib.h>
#include "define.h"
#include "struct.h"
#include "utils.h"
#include "hexa_calc.h"

bool fork_long_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    return true;
}

bool fork_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    main_t *main = (main_t *)value;
    unsigned int offset = uctoui(args[0]->arg, T_IND);
    unsigned int child_pos = 0;

    if (main->robots[robot_id].parent)
        return true;
    if (!cp_robot(&(main->robots[robot_id])))
        return false;
    child_pos = main->robots[robot_id].child->game_infos->pc;
    main->robots[robot_id].child->game_infos->pc += offset;
    return true;
}
