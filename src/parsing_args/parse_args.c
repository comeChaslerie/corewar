/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Parse all the args
*/

#include "parse_args.h"
#include "define.h"
#include "struct.h"
#include "utils.h"
#include <stdlib.h>

bool is_in_args_tab(int id, robot_args_t *robots_args, int actual_index_robot)
{
    for (unsigned int index_robot = 0; index_robot < 4; index_robot++) {
        if (index_robot == actual_index_robot)
            continue;
        if (robots_args[index_robot].id == id)
            return true;
    }
    return false;
}

static bool check_id_after_parsing(robot_args_t *robots_args)
{
    for (unsigned int index_robot = 0; index_robot < MAX_ROBOT_NBR;
        index_robot++) {
        if (robots_args[index_robot].id == NO_ID_ROBOT ||
            robots_args[index_robot].id == NO_ROBOT)
            continue;
        if (is_in_args_tab(robots_args[index_robot].id,
                robots_args, index_robot))
            return put_error("There can't be two robots with the same id.",
                false);
    }
    return true;
}

static void update_load_pos(robot_args_t *robots_args, unsigned int nbr_robots)
{
    int slice_size = (MEM_SIZE / 2) / nbr_robots;

    for (unsigned int index_tab = 0; index_tab < nbr_robots; index_tab++) {
        if (index_tab - 1 == nbr_robots)
            slice_size -= SECURE_DIST;
        if (robots_args[index_tab].load_pos == NO_VALUE_LOAD_POS)
            robots_args[index_tab].load_pos = slice_size *
                (robots_args[index_tab].id - 1);
    }
}

static bool update_id(args_t *args)
{
    unsigned int index_tab = 0;

    for (unsigned int index_robot = 1; args->robots_args[index_tab].id !=
        NO_ROBOT && index_tab < MAX_ROBOT_NBR; index_robot++) {
        if (args->robots_args[index_tab].id != NO_ID_ROBOT) {
            index_tab += 1;
            index_robot -= 1;
            continue;
        }
        if (!is_in_args_tab(index_robot, args->robots_args, NOT_ID)) {
            args->robots_args[index_tab].id = index_robot;
            index_tab += 1;
        }
    }
    args->nbr_robots = index_tab;
    if (args->nbr_robots == 0)
        return put_error("There needs to be at lest one robot.", false);
    return true;
}

bool finish_completing_struct(args_t *args)
{
    if (!update_id(args))
        return false;
    for (unsigned int index_tab = 0; index_tab < args->nbr_robots;
        index_tab++) {
        if (args->robots_args[index_tab].id > args->nbr_robots) {
            return put_error("One of the id is too high.", false);
        }
    }
    update_load_pos(args->robots_args, args->nbr_robots);
    return true;
}

args_t *parse_args(int argc, char **argv)
{
    args_t *args = NULL;

    if (argc < 2)
        return put_error("There is not enough arguments.",
            NULL);
    args = alloc_args();
    if (args == NULL)
        return put_error("Args struct alloc failed.", NULL);
    if (!check_all_flags(argc, argv, args))
        return free_args_struct(args);
    if (!check_id_after_parsing(args->robots_args))
        return free_args_struct(args);
    if (!finish_completing_struct(args))
        return free_args_struct(args);
    return args;
}
