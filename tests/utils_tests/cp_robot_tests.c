/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** cp_robot tests
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "utils.h"
#include "define.h"
#include "test_utils.h"

Test(cp_robot, null_returns_null)
{
    cr_assert_null(cp_robot(NULL));
}

Test(cp_robot, basic_copy)
{
    main_t *m = init_test_env(0);
    m->robots[0].id = 42;
    m->robots[0].game_infos->pc = 100;
    m->robots[0].game_infos->carry = true;
    m->robots[0].live = true;

    robot_infos_t *copy = cp_robot(&m->robots[0]);

    cr_assert_not_null(copy);
    cr_assert_eq(copy->id, 42);
    cr_assert_eq(copy->game_infos->pc, 100);
    cr_assert_eq(copy->game_infos->carry, true);
    cr_assert_eq(copy->live, true);
    cr_assert_eq(copy->parent, &m->robots[0]);
    cr_assert_null(copy->child);
}

Test(cp_robot, copies_registers)
{
    main_t *m = init_test_env(0);
    m->robots[0].game_infos->regs[0][0] = 0xAA;
    m->robots[0].game_infos->regs[0][3] = 0xBB;
    m->robots[0].game_infos->regs[5][2] = 0xCC;

    robot_infos_t *copy = cp_robot(&m->robots[0]);

    cr_assert_not_null(copy);
    cr_assert_eq(copy->game_infos->regs[0][0], 0xAA);
    cr_assert_eq(copy->game_infos->regs[0][3], 0xBB);
    cr_assert_eq(copy->game_infos->regs[5][2], 0xCC);
}

Test(cp_robot, regs_independent)
{
    main_t *m = init_test_env(0);
    m->robots[0].game_infos->regs[0][0] = 0x11;

    robot_infos_t *copy = cp_robot(&m->robots[0]);

    cr_assert_not_null(copy);
    m->robots[0].game_infos->regs[0][0] = 0x99;
    cr_assert_eq(copy->game_infos->regs[0][0], 0x11);
}

Test(cp_robot, cycles_remaining_reset)
{
    main_t *m = init_test_env(0);
    m->robots[0].game_infos->cycles_remaining = 50;

    robot_infos_t *copy = cp_robot(&m->robots[0]);

    cr_assert_not_null(copy);
    cr_assert_eq(copy->game_infos->cycles_remaining, 0);
}
