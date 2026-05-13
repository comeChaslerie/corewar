/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions bin calculous
*/
#include <stdbool.h>
#include "define.h"
#include "struct.h"
#include "hexa_calc.h"
#include "utils.h"

bool bin_and_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned char *rega = uctohex(args[0]->arg, args[0]->type);
    unsigned char *regb = uctohex(args[1]->arg, args[1]->type);
    unsigned char *dest = malloc(sizeof(unsigned char) * 8);
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;

    if (!rega || !regb || !dest || !hexa_and(&rega, &regb, &dest)
        || !hextouc(dest, infos->regs[(int)args[2]->arg[0]])){
        free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
        return false;
    }
    free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
    set_carry_null_reg(infos->regs[(int)args[2]->arg[0]], infos);
    return true;
}

bool bin_or_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned char *rega = uctohex(args[0]->arg, args[0]->type);
    unsigned char *regb = uctohex(args[1]->arg, args[1]->type);
    unsigned char *dest = malloc(sizeof(unsigned char) * 8);
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;

    if (!rega || !regb || !dest || !hexa_or(&rega, &regb, &dest)
        || !hextouc(dest, infos->regs[(int)args[2]->arg[0]])){
        free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
        return false;
    }
    free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
    set_carry_null_reg(infos->regs[(int)args[2]->arg[0]], infos);
    return true;
}

bool bin_xor_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned char *rega = uctohex(args[0]->arg, args[0]->type);
    unsigned char *regb = uctohex(args[1]->arg, args[1 ]->type);
    unsigned char *dest = malloc(sizeof(unsigned char) * 8);
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;

    if (!rega || !regb || !dest || !hexa_xor(&rega, &regb, &dest)
        || !hextouc(dest, infos->regs[(int)args[2]->arg[0]])){
        free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
        return false;
    }
    free_values((void *[3]){(void *)rega, (void *)regb, (void *)dest}, 3);
    set_carry_null_reg(infos->regs[(int)args[2]->arg[0]], infos);
    return true;
}

