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
    pos_infos_t *pos_infos = main->robots[robot_id].pos_infos;
    unsigned int offset = uctoui(args[0]->arg, T_IND);

    if (main->robots[robot_id].parent)
        return true;
    if (!cp_robot(&(main->robots[robot_id])))
        return false;
    main->robots[robot_id].child->pos_infos->pos_next_instr += offset;
    if (main->robots[robot_id].child->pos_infos->pos_next_instr + offset >
        main->robots[robot_id].child->pos_infos->pos_end)
        main->robots[robot_id].child->pos_infos->pos_next_instr =
            main->robots[robot_id].child->pos_infos->pos_start;
    return true;
}
