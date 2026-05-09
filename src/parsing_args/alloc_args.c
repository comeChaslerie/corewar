/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** alloc the ars struct
*/

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
