/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdlib.h>
#include "struct.h"

void set_carry_null_reg(unsigned char *reg,
    robot_game_infos_t *game_infos)
{
    game_infos->carry = true;
    for (unsigned int i = 0; i < REG_SIZE; i++)
        if (reg[i] != 0)
            game_infos->carry = false;
}
