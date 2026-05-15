/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions load
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "struct.h"
#include "utils.h"
#include "compute.h"

bool fork_long_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    main_t *main = (main_t *)value;
    unsigned int offset = uctoui(args[0]->arg, args[0]->size);
    robot_infos_t *child = &(main->robots[robot_id]);

    while (child && child->child)
        child = child->child;
    child->child = cp_robot(&(main->robots[robot_id]));
    if (!child->child)
        return false;
    child->child->game_infos->pc = (child->child->game_infos->pc +
        offset) % MEM_SIZE;
    return true;
}

bool fork_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    main_t *main = (main_t *)value;
    unsigned int offset = uctoui(args[0]->arg, args[0]->size);
    robot_infos_t *child = &(main->robots[robot_id]);

    while (child && child->child)
        child = child->child;
    child->child = cp_robot(&(main->robots[robot_id]));
    if (!child->child)
        return false;
    child->child->game_infos->pc = (child->child->game_infos->pc +
        offset % IDX_MOD) % MEM_SIZE;
    return true;
}
