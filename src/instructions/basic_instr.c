/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions basic
*/

#include <stdbool.h>
#include <stdlib.h>
#include "compute.h"
#include "define.h"
#include "struct.h"
#include "utils.h"

bool live_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int player_id = uctoui(args[0]->arg, T_DIR);

    ((main_t *)value)->robots[player_id].live = true;
    ((main_t *)value)->nb_live++;
    return true;
}

bool add_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned char *rega = uctohex(args[0]->arg, args[0]->type);
    unsigned char *regb = uctohex(args[1]->arg, args[1]->type);
    unsigned char *dest = malloc(sizeof(unsigned char) * 8);
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;

    if (!rega || !regb || !dest || !hexa_sum(&rega, &regb, &dest)
        || !hextouc(dest, infos->regs[(int)args[2]->arg[0]])){
        free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
        return false;
    }
    free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
    set_carry_null_reg(infos->regs[(int)args[2]->arg[0]], infos);
    return true;
}

bool sub_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned char *rega = uctohex(args[0]->arg, args[0]->type);
    unsigned char *regb = uctohex(args[1]->arg, args[1]->type);
    unsigned char *dest = malloc(sizeof(unsigned char) * 8);
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;

    if (!rega || !regb || !dest || !hexa_diff(&rega, &regb, &dest)
        || !hextouc(dest, infos->regs[(int)args[2]->arg[0]])){
        free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
        return false;
    }
    free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
    set_carry_null_reg(infos->regs[(int)args[2]->arg[0]], infos);
    return true;
}

bool print_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned char *reg = uctohex(args[0]->arg, args[0]->type);

    if (!reg) {
        free_values((void *[1]){(void *)reg}, 1);
        return false;
    }
    for (unsigned int i = 0; i < REG_SIZE; i++)
        my_putchar((char)reg[i]);
    free_values((void *[1]){(void *)reg}, 1);
    return true;
}

bool jump_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int jump = uctoui(args[0]->arg, T_IND);
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;

    if (infos->carry)
        infos->pc += (jump % IDX_MOD) % MEM_SIZE;
    return true;
}
