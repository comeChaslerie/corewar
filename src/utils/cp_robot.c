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

static bool cp_robot_infos(robot_infos_t *src_robot, robot_infos_t *dest_robot)
{
    dest_robot->game_infos = malloc(sizeof(robot_game_infos_t) * 1);
    if (!dest_robot->game_infos)
        return put_error("malloc failed in cp_robot_infos", false);
    dest_robot->game_infos->carry = src_robot->game_infos->carry;
    dest_robot->game_infos->cycles_remaining = 0;
    dest_robot->game_infos->pc = src_robot->game_infos->pc;
    dest_robot->game_infos->regs = malloc(sizeof(unsigned char *) *
        REG_NUMBER);
    if (!dest_robot->game_infos->regs)
        return put_error("malloc failed in cp_robot_infos", false);
    for (unsigned int i = 0; i < REG_NUMBER; i++){
        dest_robot->game_infos->regs[i] =
            my_ustrndup(src_robot->game_infos->regs[i], 0, REG_SIZE);
        if (!dest_robot->game_infos->regs[i])
            return put_error("malloc failed in cp_robot_infos", false);
    }
    return true;
}

robot_infos_t *cp_robot(robot_infos_t *src_robot)
{
    robot_infos_t *dest_robot = NULL;

    if (!src_robot)
        return false;
    dest_robot = malloc(sizeof(robot_infos_t) * 1);
    if (!dest_robot)
        return put_error("malloc failed in cp_robot.\n", false);
    dest_robot->child = NULL;
    dest_robot->parent = src_robot;
    dest_robot->header = src_robot->header;
    dest_robot->id = src_robot->id;
    if (!cp_robot_infos(src_robot, dest_robot))
        return NULL;
    return dest_robot;
}
