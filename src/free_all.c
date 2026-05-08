/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** free the structs
*/
#include "op_define.h"
#include "parse_args.h"
#include "struct.h"
#include "handle_main.h"
#include <stdlib.h>

void *free_args_struct(args_t *args)
{
    if (args == NULL)
        return NULL;
    if (args->robots_args == NULL)
        return NULL;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (args->robots_args[index].filepath != NULL)
            free(args->robots_args[index].filepath);
    }
    free(args->robots_args);
    free(args);
    return NULL;
}

void *free_robots(main_t *main, void *return_value)
{
    if (main->robots == NULL)
        return return_value;
    for (unsigned int index = 0; index < main->nbr_robots; index++) {
        if (main->robots[index].pos_infos != NULL)
            free(main->robots[index].pos_infos);
        if (main->robots[index].game_infos != NULL &&
            main->robots[index].game_infos->regs != NULL) {
            free(main->robots[index].game_infos->regs);
            free(main->robots[index].game_infos);
        }
    }
    free(main->robots);
    return return_value;
}

void *free_main(char *str, main_t *main, args_t *args)
{
    if (main == NULL)
        return free_args_struct(args);
    if (main->arena != NULL)
        free(main->arena);
    if (main->robots != NULL) {
        free_robots(main, NULL);
    }
    free(main);
    return NULL;
}
