/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** free the structs
*/
#include "define.h"
#include "parse_args.h"
#include "struct.h"
#include "handle_main.h"
#include <stdio.h>
#include <stdlib.h>

void free_instr(instr_t *instr)
{
    if (!instr)
        return;
    for (unsigned int i = 0; i < MAX_ARGS_NUMBER; i++)
        if (instr->args[i])
            free(instr->args[i]);
    free(instr);
}

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

static void free_infos(robot_game_infos_t *infos)
{
    if (!infos)
        return;
    for (unsigned int i = 0; i < REG_NUMBER && infos->regs; i++)
        if (infos->regs[i])
            free(infos->regs[i]);
    if (infos->regs)
        free(infos->regs);
    free(infos);
}

static void free_robot(robot_infos_t *infos)
{
    if (!infos)
        return;
    if (infos->pos_infos)
        free(infos->pos_infos);
    if (infos->game_infos)
        free_infos(infos->game_infos);
    if (infos->child)
        free_robot(infos->child);
    free(infos);
}

void *free_robots(main_t *main)
{
    if (main->robots == NULL)
        return NULL;
    for (unsigned int index = 0; index < main->nbr_robots; index++) {
        free_robot(&(main->robots[index]));
    }
    free(main->robots);
    return NULL;
}

void *free_main(char *str, main_t *main, args_t *args)
{
    if (!main)
        return NULL;
    if (main->arena)
        free(main->arena);
    if (main->robots != NULL) {
        free_robots(main);
    }
    free(main);
    return NULL;
}
