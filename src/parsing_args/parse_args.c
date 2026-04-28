/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Parse all the args
*/

#include "parse_args.h"
#include "op.h"
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

static bool check_after_parsing(robot_args_t *robots_args)
{
    for (unsigned int index_robot = 0; index_robot < 4; index_robot++) {
        if (robots_args[index_robot].id == 0 ||
            robots_args[index_robot].id == -1)
            continue;
        if (is_in_args_tab(robots_args[index_robot].id,
                robots_args, index_robot))
            return put_error("There can't be two robots with the same id.",
                false);
    }
    return true;
}

static bool is_a_flag(char *elem)
{
    if (elem[0] != '-')
        return true;
    if (elem[0] == '-' && elem[1] != '\0')
        if ((my_strcmp(elem, "-dump") == 0 || elem[1] == 'a' || elem[1] == 'n')
            && elem[2] == '\0')
            return true;
    return false;
}

bool check_all_flags(int argc, char **argv, args_t *args)
{
    unsigned int robot_index = 0;

    for (unsigned int index = 1; index < argc; index++) {
        if (!manage_flag_dump(argc, argv, &index, args))
            return false;
        if (!manage_flag_load(argc, argv, &index,
                &args->robots_args[robot_index]))
            return false;
        if (!manage_flag_id(argc, argv, &index,
                &args->robots_args[robot_index]))
            return false;
        if (!manage_flags_robot(argv, &index, &robot_index, args))
            return false;
        if (!is_a_flag(argv[index]))
            return put_error("The flag doesn't exist.", false);
    }
    return true;
}

static int update_id(robot_args_t *robots_args)
{
    unsigned int index_tab = 0;

    for (unsigned int index_robot = 1; robots_args[index_tab].id != -1 &&
        index_robot <= MAX_ROBOT_NBR; index_robot++) {
        if (robots_args[index_tab].id != 0) {
            index_tab += 1;
            index_robot -= 1;
            continue;
        }
        if (!is_in_args_tab(index_robot, robots_args, -2)) {
            robots_args[index_tab].id = index_robot;
            index_tab += 1;
        }
    }
    return index_tab;
}

static void update_load_pos(robot_args_t *robots_args, unsigned int nbr_robots)
{
    int slice_size = MEM_SIZE / nbr_robots;

    for (unsigned int index_tab = 0; index_tab <= nbr_robots; index_tab++) {
        if (robots_args[index_tab].load_pos == -1)
            robots_args[index_tab].load_pos = slice_size *
                (robots_args[index_tab].id - 1);
    }
}

bool finish_completing_struct(args_t *args)
{
    args->nbr_robots = update_id(args->robots_args);
    for (unsigned int index_tab = 0; index_tab < args->nbr_robots;
        index_tab++) {
        if (args->robots_args[index_tab].id > args->nbr_robots)
            return put_error("One of the id is too high.", false);
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
    if (!check_after_parsing(args->robots_args))
        return free_args_struct(args);
    if (!finish_completing_struct(args))
        return free_args_struct(args);
    return args;
}
