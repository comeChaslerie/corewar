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
        if (instr->args[i]) {
            free(instr->args[i]->arg);
            free(instr->args[i]);
        }
    free(instr);
}

void free_args_struct(args_t *args)
{
    if (!args)
        return;
    if (args->robots_args == NULL)
        return;
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (args->robots_args[index].filepath != NULL)
            free(args->robots_args[index].filepath);
    }
    free(args->robots_args);
    free(args);
    return;
}

static void free_game_infos(robot_game_infos_t *infos)
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

static void free_child_chain(robot_infos_t *child)
{
    robot_infos_t *next = NULL;

    while (child) {
        next = child->child;
        if (child->game_infos)
            free_game_infos(child->game_infos);
        free(child);
        child = next;
    }
}

static void free_robot_contents(robot_infos_t *infos)
{
    if (!infos)
        return;
    if (infos->game_infos)
        free_game_infos(infos->game_infos);
    if (infos->child)
        free_child_chain(infos->child);
    infos->child = NULL;
}

void free_robots(main_t *main)
{
    if (main->robots == NULL)
        return;
    for (unsigned int i = 0; i < main->nbr_robots; i++)
        free_robot_contents(&main->robots[i]);
    free(main->robots);
    return;
}

void free_main(main_t *main, args_t *args)
{
    if (!main)
        return;
    if (main->arena)
        free(main->arena);
    if (main->robots != NULL) {
        free_robots(main);
    }
    free(main);
    return;
}
