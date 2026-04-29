/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Manage the flags individually
*/

#include "parse_args.h"
#include "struct.h"
#include "utils.h"
#include <stdlib.h>

static bool check_following_nb(int argc, char **argv,
    unsigned int *index, int *nbr)
{
    *index += 1;
    if (*index > argc)
        return put_error("Missing argument after a flag.", false);
    if (!is_nbr(argv[*index]))
        return put_error("The argument for the flag isn't in the right format.",
            false);
    *nbr = my_getnbr(argv[*index], 0);
    return true;
}

bool manage_flag_dump(int argc, char **argv, unsigned int *index, args_t *args)
{
    if (*index > argc)
        return true;
    if (my_strcmp(argv[*index], "-dump") == 0) {
        if (args->cycle_dump != -1)
            return put_error("Too many -d flags.", false);
        if (!check_following_nb(argc, argv, index, &args->cycle_dump))
            return false;
        if (args->cycle_dump > CYCLE_TO_DIE || args->cycle_dump < 0)
            return put_error("The argument for the -d flag is out of range.",
                false);
        *index += 1;
    }
    return true;
}

bool manage_flag_load(int argc, char **argv, unsigned int *index,
    robot_args_t *robots_args)
{
    if (*index > argc)
        return true;
    if (my_strcmp(argv[*index], "-a") == 0) {
        if (robots_args->load_pos != -1)
            return put_error("Too many -a flags for one robot.",
                false);
        if (!check_following_nb(argc, argv, index, &robots_args->load_pos))
            return false;
        if (robots_args->load_pos > MEM_SIZE || robots_args->load_pos < 0)
            return put_error("The argument for the -a flag is out of range.",
                false);
        *index += 1;
    }
    return true;
}

bool manage_flag_id(int argc, char **argv, unsigned int *index,
    robot_args_t *robots_args)
{
    if (*index > argc)
        return true;
    if (my_strcmp(argv[*index], "-n") == 0) {
        if (robots_args->id != -1)
            return put_error("Too many -n flags for one robot.",
                false);
        if (!check_following_nb(argc, argv, index, &robots_args->id))
            return false;
        if (robots_args->id > 4 || robots_args->id < 0)
            return put_error("The argument for the -n flag is out of range.",
                false);
        *index += 1;
    }
    return true;
}

bool manage_flags_robot(char **argv, unsigned int *index,
    unsigned int *robot_index, args_t *args)
{
    if (argv[*index] == NULL)
        return true;
    if (argv[*index][0] != '-' && index != 0 && argv[*index - 1][0] != '-') {
        args->robots_args[*robot_index].filepath = my_strdup(argv[*index]);
        if (args->robots_args[*robot_index].id == -1)
            args->robots_args[*robot_index].id = 0;
        *robot_index += 1;
    }
    if (*robot_index == 4 && argv[*index + 1] != NULL)
        return put_error("There can be only 4 robots.", false);
    return true;
}
