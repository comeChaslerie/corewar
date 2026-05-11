/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdbool.h>
#include <stdlib.h>
#include "define.h"
#include "struct.h"
#include "utils.h"

static bool cp_robot_infos(robot_infos_t *robot)
{
    robot->child->game_infos = malloc(sizeof(robot_game_infos_t) * 1);
    if (!robot->child->game_infos)
        return put_error("malloc failed in cp_robot_infos", false);
    robot->child->game_infos->carry = robot->game_infos->carry;
    robot->child->game_infos->cycles_remaining =
        robot->game_infos->cycles_remaining;
    robot->child->game_infos->pc = robot->game_infos->pc;
    robot->child->game_infos->regs = malloc(sizeof(unsigned char *) * 1);
    if (!robot->child->game_infos->regs)
        return put_error("malloc failed in cp_robot_infos", false);
    for (unsigned int i = 0; i < REG_NUMBER; i++){
        robot->child->game_infos->regs[i] =
            my_ustrndup(robot->game_infos->regs[i], 0, REG_SIZE);
        if (!robot->child->game_infos->regs[i])
            return put_error("malloc failed in cp_robot_infos", false);
    }
    return true;
}

static bool cp_robot_pos(robot_infos_t *robot)
{
    robot->child->pos_infos = malloc(sizeof(pos_infos_t *) * 1);
    if (!robot->child->pos_infos)
        return put_error("malloc failed in cp_robot_pos", false);
    robot->child->pos_infos->pos_end = robot->pos_infos->pos_end;
    robot->child->pos_infos->pos_next_instr = robot->pos_infos->pos_next_instr;
    robot->child->pos_infos->pos_start = robot->pos_infos->pos_start;
    return true;
}

bool cp_robot(robot_infos_t *robot)
{
    if (robot->child)
        return true;
    robot->child = malloc(sizeof(robot_infos_t *) * 1);
    if (!robot->child)
        return put_error("malloc failed in cp_robot.\n", false);
    robot->child->child = NULL;
    robot->child->parent = robot;
    robot->child->header = robot->header;
    robot->child->id = robot->id;
    if (!cp_robot_infos(robot) || !cp_robot_pos(robot))
        return false;
    return true;
}
