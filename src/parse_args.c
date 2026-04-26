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

bool check_all_flags(int argc, char **argv, unsigned int *robot_index, args_t *args)
{
    for (unsigned int index = 1; index < argc; index++) {
        if (!manage_flag_dump(argc, argv, &index, args))
            return free_args_struct(args);
        if (!manage_flag_load(argc, argv, &index, &args->robots_args[*robot_index]))
            return free_args_struct(args);
        if (!manage_flag_id(argc, argv, &index, &args->robots_args[*robot_index]))
            return free_args_struct(args);
        if (!manage_flags_robot(argv, &index, robot_index, args))
            return free_args_struct(args);
    }
    return true;
}

args_t *parse_args(int argc, char **argv)
{
    args_t *args = NULL;
    unsigned int robot_index = 0;

    if (argc < 3)
        return put_error("The number of args is not enough.", NULL);
    args = alloc_args();
    if (args == NULL)
        return put_error("Args struct alloc failed.", NULL);
    if (check_all_flags(argc, argv, &robot_index, args))
        return NULL;
    if (robot_index < 2) {
        put_error("There needs to be at least two robots.", NULL);
        return free_args_struct(args);
    }
    if (args->cycle_dump == -1) {
        put_error("There needs to be a -d flag.", NULL);
        return free_args_struct(args);
    }
    return args;
}
