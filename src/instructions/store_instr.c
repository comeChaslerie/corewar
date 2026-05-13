/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions load
*/
#include <stdbool.h>
#include "define.h"
#include "struct.h"
#include "compute.h"

bool store_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int src = (unsigned int)args[0]->arg[0];
    unsigned int dest = 0;
    main_t *main = (main_t *)value;
    unsigned char **regs = main->robots[robot_id].game_infos->regs;

    if (args[1]->type == T_REG){
        dest = (unsigned int)args[1]->arg[0];
        for (unsigned int i = 0; i < REG_SIZE; i++)
            regs[dest][i] = regs[src][i];
        return true;
    }
    dest = uctoui(args[1]->arg, args[1]->type);
    dest = (main->robots[robot_id].game_infos->pc + dest % IDX_MOD) % MEM_SIZE;
    for (unsigned int i = 0; i < REG_SIZE; i++)
        main->arena[dest + i] = regs[src][i];
    return true;
}

bool store_ind_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int src = (unsigned int)args[0]->arg[0];
    unsigned int val_a = uctoui(args[1]->arg, args[1]->type);
    unsigned int val_b = uctoui(args[2]->arg, args[2]->type);
    unsigned int dest = 0;
    main_t *main = (main_t *)value;
    unsigned char **regs = main->robots[robot_id].game_infos->regs;

    dest = (main->robots[robot_id].game_infos->pc + (val_a + val_b) % IDX_MOD)
        % MEM_SIZE;
    for (unsigned int i = 0; i < REG_SIZE; i++)
        main->arena[dest + i] = regs[src][i];
    return true;
}
