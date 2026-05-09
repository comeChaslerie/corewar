/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions basic
*/

#include <stdbool.h>
#include <stdlib.h>
#include "hexa_calc.h"
#include "op_define.h"
#include "struct.h"
#include "utils.h"

bool live_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int start = ((main_t *)value)->robots[(int)(args[0]->arg[0])]
        .pos_infos->pos_next_instr;
    unsigned int end = ((main_t *)value)->robots[(int)(args[0]->arg[0])]
        .pos_infos->pos_end;

    if (start > end)
        return false;
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

    if (!rega || !regb || !dest || !hexa_sum(&rega, &regb, &dest)
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
    return true;
}

bool jump_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int jump = uctoui(args[0]->arg, T_IND);
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;
    pos_infos_t *pos_infos = ((main_t *)value)->robots[robot_id].pos_infos;

    if (infos->carry)
        pos_infos->pos_next_instr += jump;
    return true;
}
