/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Manage the flags individually
*/

#include "define.h"
#include "parse_args.h"
#include "struct.h"
#include "utils.h"
#include <stdlib.h>

static bool is_a_flag(char *elem, unsigned int *index)
{
    if (elem == NULL)
        return true;
    if (elem[0] != FLAG_CHAR)
        return true;
    *index -= 1;
    if (my_strcmp(elem, DUMP_FLAG) == SUCCESS ||
        my_strcmp(elem, LOAD_FLAG) == SUCCESS ||
        my_strcmp(elem, ID_FLAG) == SUCCESS) {
        return true;
    }
    return false;
}

bool manage_flags_robot(char **argv, unsigned int *index,
    unsigned int *robot_index, args_t *args)
{
    if (argv[*index] == NULL)
        return true;
    if (argv[*index][0] != FLAG_CHAR && index != 0 &&
        argv[*index - 1][0] != FLAG_CHAR) {
        args->robots_args[*robot_index].filepath = my_strdup(argv[*index]);
        if (args->robots_args[*robot_index].id == NO_ROBOT)
            args->robots_args[*robot_index].id = NO_ID_ROBOT;
        *robot_index += 1;
    }
    if (*robot_index > MAX_ROBOT_NBR)
        return put_error("There can be only 4 robots.", false);
    return true;
}

static bool check_following_nb(int argc, char **argv,
    unsigned int *index, int *nbr)
{
    *index += 1;
    if (*index >= argc)
        return put_error("Missing argument after a flag.", false);
    if (!is_nbr(argv[*index]))
        return put_error("The argument for the flag isn't in the right format.",
            false);
    *nbr = my_getnbr(argv[*index], 0);
    return true;
}

bool manage_flag_id(int argc, char **argv, unsigned int *index,
    robot_args_t *robots_args)
{
    if (*index >= argc)
        return true;
    if (my_strcmp(argv[*index], "-n") == SUCCESS) {
        if (robots_args->id != NO_ROBOT)
            return put_error("Too many -n flags for one robot.",
                false);
        if (!check_following_nb(argc, argv, index, &robots_args->id))
            return false;
        if (robots_args->id > MAX_ROBOT_NBR || robots_args->id < 0)
            return put_error("The argument for the -n flag is out of range.",
                false);
        *index += 1;
    }
    return true;
}

bool manage_flag_load(int argc, char **argv, unsigned int *index,
    robot_args_t *robots_args)
{
    if (*index >= argc)
        return true;
    if (my_strcmp(argv[*index], "-a") == SUCCESS) {
        if (robots_args->load_pos != NO_VALUE_LOAD_POS)
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

bool manage_flag_dump(int argc, char **argv, unsigned int *index, args_t *args)
{
    if (*index >= argc)
        return true;
    if (my_strcmp(argv[*index], "-dump") == SUCCESS) {
        if (args->cycle_dump != NO_CYCLE_DUMP)
            return put_error("Too many -dump flags.", false);
        if (!check_following_nb(argc, argv, index, &args->cycle_dump))
            return false;
        *index += 1;
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
        if (!is_a_flag(argv[index], &index))
            return put_error("The flag doesn't exist.", false);
    }
    return true;
}
