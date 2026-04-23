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

void *free_args_struct(args_t *args)
{
    if (args == NULL)
        return NULL;
    if (args->robots_args == NULL)
        return NULL;
    free(args->robots_args);
    free(args);
    return NULL;
}

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
    for (unsigned int robot_index = 0; robot_index < MAX_ROBOT_NBR; robot_index++) {
        args->robots_args[robot_index].filepath_tab = NULL;
        args->robots_args[robot_index].id_tab = 0;
        args->robots_args[robot_index].load_pos = -1;
    }
    return args;
}

bool is_nbr(char *str)
{
    for (unsigned int index = 0; index < my_strlen(str); index++) {
        if (str[index] < '0' || str[index] > '9')
            return false;
    }
    return true;
}

bool manage_flag_dump(char **argv, unsigned int index, args_t *args)
{
    if (my_strcmp(argv[index], "-d") == -1) {
        if (args->cycle_dump != 0)
            return put_error("Too many -d flags.", false);
        if (argv[index + 1] == NULL)
            return put_error("Missing argument for th -d flag.", false);
        if (!is_nbr(argv[index + 1]))
            return put_error("The argument for the -d flag isn't in the right format.", false);
        args->cycle_dump = my_getnbr(argv[index + 1], 0);
        if (args->cycle_dump > CYCLE_TO_DIE || args->cycle_dump < 0)
            return put_error("The argument for the -d flag is out of range.", false);
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
    for (unsigned int index = 1; argv[index] != NULL; index++) {
        if (!(bool)manage_flag_dump(argv, index, args))
            return free_args_struct(args);
    }
    return args;
}
