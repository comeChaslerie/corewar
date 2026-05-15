/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** set_carry_null_reg tests
*/
#include <criterion/criterion.h>
#include "utils.h"
#include "define.h"

Test(set_carry, all_zero_sets_carry)
{
    unsigned char reg[REG_SIZE] = {0, 0, 0, 0};
    robot_game_infos_t infos = {0};

    set_carry_null_reg(reg, &infos);
    cr_assert_eq(infos.carry, true);
}

Test(set_carry, non_zero_clears_carry)
{
    unsigned char reg[REG_SIZE] = {0, 0, 0, 1};
    robot_game_infos_t infos = {0};

    infos.carry = true;
    set_carry_null_reg(reg, &infos);
    cr_assert_eq(infos.carry, false);
}

Test(set_carry, first_byte_only)
{
    unsigned char reg[REG_SIZE] = {0xFF, 0, 0, 0};
    robot_game_infos_t infos = {0};

    set_carry_null_reg(reg, &infos);
    cr_assert_eq(infos.carry, false);
}

Test(set_carry, last_byte_only)
{
    unsigned char reg[REG_SIZE] = {0, 0, 0, 0xFF};
    robot_game_infos_t infos = {0};

    set_carry_null_reg(reg, &infos);
    cr_assert_eq(infos.carry, false);
}

Test(set_carry, all_max)
{
    unsigned char reg[REG_SIZE] = {0xFF, 0xFF, 0xFF, 0xFF};
    robot_game_infos_t infos = {0};

    set_carry_null_reg(reg, &infos);
    cr_assert_eq(infos.carry, false);
}
