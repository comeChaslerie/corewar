/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Parse all the args
*/

#include "parse_args.h"
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

bool check_after_parsing(args_t *args)
{
    if (args->cycle_dump == -1)
        return put_error("There needs to be a -d flag.", false);
    for (unsigned int index_robot = 0; index_robot < 4; index_robot++) {
        if (args->robots_args[index_robot].id == -1)
            continue;
        if (is_in_args_tab(args->robots_args[index_robot].id,
                args->robots_args, index_robot))
            return put_error("There can't be two robots with the same id.",
                false);
    }
    return true;
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
    }
    if (robot_index < 2)
        return put_error("There needs to be at least two robots.",
            false);
    return true;
}

args_t *parse_args(int argc, char **argv)
{
    args_t *args = NULL;

    if (argc < 3)
        return put_error("There is not enough arguments.",
            NULL);
    args = alloc_args();
    if (args == NULL)
        return put_error("Args struct alloc failed.", NULL);
    if (!check_all_flags(argc, argv, args))
        return free_args_struct(args);
    if (!check_after_parsing(args))
        return free_args_struct(args);
    return args;
}
