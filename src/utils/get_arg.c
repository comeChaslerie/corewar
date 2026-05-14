/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "compute.h"
#include "define.h"
#include "struct.h"
#include "utils.h"
#include <stdlib.h>

static unsigned char *get_arg_reg_type(arg_t *arg, unsigned char **regs)
{
    unsigned char *arg_content = NULL;
    unsigned int u_arg = 0;

    u_arg = uctoui(arg->arg, arg->size);
    if (u_arg < 0 || u_arg > REG_NUMBER)
        return false;
    arg_content = my_ustrndup(regs[u_arg], 0, REG_SIZE);
    if (!arg_content)
        return NULL;
    return arg_content;
}

static unsigned char *get_arg_ind_type(arg_t *arg, unsigned int pc,
    unsigned char *arena)
{
    unsigned char *arg_content = NULL;
    unsigned int u_arg = 0;

    u_arg = uctoui(arg->arg, arg->size);
    u_arg = ((pc + u_arg % IDX_MOD) % MEM_SIZE);
    arg_content = my_ustrndup(arena, u_arg, u_arg + DIR_SIZE);
    if (!arg_content)
        return NULL;
    return arg_content;
}

unsigned char *get_arg_content(arg_t *arg, unsigned int robot_id, main_t *main)
{
    unsigned char **regs = main->robots[robot_id].game_infos->regs;
    unsigned int pc = main->robots[robot_id].game_infos->pc;

    if (arg->type == T_IND || arg->type == T_DIR)
        return get_arg_ind_type(arg, pc, main->arena);
    if (arg->type == T_REG)
        return get_arg_reg_type(arg, regs);
    return NULL;
}

unsigned int get_u_arg_content(arg_t *arg, unsigned int robot_id, main_t *main)
{
    unsigned char *arg_content = get_arg_content(arg, robot_id, main);
    unsigned int u_arg_content = 0;

    if (!arg_content)
        return 0;
    u_arg_content = uctoui(arg_content, arg->size);
    free(arg_content);
    return u_arg_content;
}
