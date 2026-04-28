/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Parse all the args
*/
#include <stdbool.h>
#include <stdio.h>
#include "struct.h"

int my_htonl(int val)
{
    int result = 0;

    result = (val >> 24) & 0xFF;
    result += (val >> 8) & 0xFF00;
    result += (val << 8) & 0xFF0000;
    result += (val << 24) & 0xFF000000;
    return result;
}

bool fill_robot_instr(main_t *main, robot_infos_t *robot_infos, robot_args_t *robot_args)
{
    FILE *fp = fopen(robot_args->filepath, "r");

    if (fp == NULL)
        return false;
    fread(&robot_infos->header, sizeof(header_t), 1, fp);
    if (my_htonl(robot_infos->header.magic) != COREWAR_EXEC_MAGIC)
        return false;
    return true;
}
