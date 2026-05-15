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

args_t *alloc_args(void)
{
    args_t *args = malloc(sizeof(args_t));

    if (args == NULL)
        return put_error("Args struct alloc failed.", NULL);
    args->cycle_dump = -1;
    args->nbr_robots = 0;
    args->robots_args = malloc(sizeof(robot_args_t) * MAX_ROBOT_NBR);
    if (args->robots_args == NULL) {
        free(args);
        return put_error("Robots args alloc failed.", NULL);
    }
    for (unsigned int robot_index = 0; robot_index < MAX_ROBOT_NBR;
        robot_index++) {
        args->robots_args[robot_index].filepath = NULL;
        args->robots_args[robot_index].id = NO_ROBOT;
        args->robots_args[robot_index].load_pos = NO_VALUE_LOAD_POS;
    }
    return args;
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
    if (!check_all_flags(argc, argv, args) ||
        !check_id_after_parsing(args->robots_args) || !update_id(args)) {
        free_args_struct(args);
        return NULL;
    }
    update_load_pos(args->robots_args, args->nbr_robots);
    return args;
}
