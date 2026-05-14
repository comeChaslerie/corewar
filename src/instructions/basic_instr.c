/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instructions functions basic
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "compute.h"
#include "define.h"
#include "struct.h"
#include "utils.h"

static void display_live(robot_infos_t *robot)
{
    write(1, "The player ", 11);
    my_put_nbr_u(robot->id);
    write(1, "(", 1);
    write(1, robot->header.prog_name, my_strlen(robot->header.prog_name));
    write(1, ") is alive.\n", 12);
}

bool live_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned int player_id = uctoui(args[0]->arg, args[0]->size);
    main_t *main = (main_t *)value;

    for (unsigned int i = 0; i < main->nbr_robots; i++) {
        if (main->robots[i].id == player_id) {
            main->robots[i].live = true;
            main->nb_live++;
            display_live(&main->robots[i]);
            return true;
        }
    }
    return true;
}

bool add_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;
    unsigned char *reg_a = uctohex(infos->regs[(int)args[0]->arg[0]], REG_SIZE);
    unsigned char *reg_b = uctohex(infos->regs[(int)args[1]->arg[0]], REG_SIZE);
    unsigned char *dest = malloc(sizeof(unsigned char) * HEXA_SIZE);

    if (!reg_a || !reg_b || !dest || !hexa_sum(&reg_a, &reg_b, &dest)
        || !hextouc(dest, infos->regs[(int)args[2]->arg[0]])){
        free_values((void *[3]){(void *)reg_a, (void *)reg_b, (void *)dest}, 3);
        return false;
    }
    free_values((void *[3]){(void *)reg_a, (void *)reg_b, (void *)dest}, 3);
    set_carry_null_reg(infos->regs[(int)args[2]->arg[0]], infos);
    return true;
}

bool sub_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;
    unsigned char *reg_a = uctohex(infos->regs[(int)args[0]->arg[0]], REG_SIZE);
    unsigned char *reg_b = uctohex(infos->regs[(int)args[1]->arg[0]], REG_SIZE);
    unsigned char *dest = malloc(sizeof(unsigned char) * HEXA_SIZE);

    if (!reg_a || !reg_b || !dest || !hexa_diff(&reg_a, &reg_b, &dest)
        || !hextouc(dest, infos->regs[(int)args[2]->arg[0]])){
        free_values((void *[3]){(void *)reg_a, (void *)reg_b, (void *)dest}, 3);
        return false;
    }
    free_values((void *[3]){(void *)reg_a, (void *)reg_b, (void *)dest}, 3);
    set_carry_null_reg(infos->regs[(int)args[2]->arg[0]], infos);
    return true;
}

bool print_instr(void *value, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id)
{
    unsigned char **regs = ((main_t *)value)->robots[robot_id].game_infos->regs;
    unsigned char *reg = uctohex(regs[args[0]->arg[0]], args[0]->size);

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
    unsigned int jump = uctoui(args[0]->arg, args[0]->size);
    robot_game_infos_t *infos = ((main_t *)value)->robots[robot_id].game_infos;

    infos->pc = (infos->pc + jump % IDX_MOD) % MEM_SIZE;
    return true;
}
