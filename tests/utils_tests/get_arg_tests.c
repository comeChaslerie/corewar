/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** get_arg tests
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "game.h"
#include "define.h"
#include "test_utils.h"

Test(get_arg_content, dir_type)
{
    main_t *m = init_test_env(0);
    arg_t *a = create_arg(T_DIR, REG_SIZE,
        (unsigned char[]){0xAA, 0xBB, 0xCC, 0xDD});

    unsigned char *res = get_arg_content(a, 0, m);

    cr_assert_not_null(res);
    cr_assert_eq(res[0], 0xAA);
    cr_assert_eq(res[1], 0xBB);
    cr_assert_eq(res[2], 0xCC);
    cr_assert_eq(res[3], 0xDD);
    free(res);
}

Test(get_arg_content, ind_type)
{
    main_t *m = init_test_env(0);
    m->robots[0].game_infos->pc = 100;
    m->arena[110] = 0x11;
    m->arena[111] = 0x22;
    m->arena[112] = 0x33;
    m->arena[113] = 0x44;
    arg_t *a = create_arg(T_IND, IND_SIZE, (unsigned char[]){0, 10});

    unsigned char *res = get_arg_content(a, 0, m);

    cr_assert_not_null(res);
    cr_assert_eq(res[0], 0x11);
    cr_assert_eq(res[1], 0x22);
    cr_assert_eq(res[2], 0x33);
    cr_assert_eq(res[3], 0x44);
    free(res);
}

Test(get_arg_content, reg_type)
{
    main_t *m = init_test_env(0);
    m->robots[0].game_infos->regs[3][0] = 0x99;
    m->robots[0].game_infos->regs[3][3] = 0x77;
    arg_t *a = create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){3});

    unsigned char *res = get_arg_content(a, 0, m);

    cr_assert_not_null(res);
    cr_assert_eq(res[0], 0x99);
    cr_assert_eq(res[3], 0x77);
    free(res);
}

Test(get_arg_content, lab_returns_null)
{
    main_t *m = init_test_env(0);
    arg_t *a = create_arg(T_LAB, REG_SIZE, (unsigned char[]){0, 0, 0, 0});

    cr_assert_null(get_arg_content(a, 0, m));
}

Test(get_u_arg_content, dir_type)
{
    main_t *m = init_test_env(0);
    arg_t *a = create_arg(T_DIR, REG_SIZE,
        (unsigned char[]){0, 0, 0, 0x2A});

    cr_assert_eq(get_u_arg_content(a, 0, m), 42);
}

Test(get_u_arg_content, reg_type)
{
    main_t *m = init_test_env(0);
    m->robots[0].game_infos->regs[1][0] = 99;
    arg_t *a = create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){1});

    cr_assert_eq(get_u_arg_content(a, 0, m), 99);
}

Test(get_u_arg_content, lab_returns_zero)
{
    main_t *m = init_test_env(0);
    arg_t *a = create_arg(T_LAB, REG_SIZE, (unsigned char[]){0, 0, 0, 0});

    cr_assert_eq(get_u_arg_content(a, 0, m), 0);
}

Test(get_arg_content, ind_pc_wrap)
{
    main_t *m = init_test_env(0);
    m->robots[0].game_infos->pc = MEM_SIZE - 5;
    m->arena[5] = 0xDE;
    m->arena[6] = 0xAD;
    m->arena[7] = 0xBE;
    m->arena[8] = 0xEF;
    arg_t *a = create_arg(T_IND, IND_SIZE, (unsigned char[]){0, 10});

    unsigned char *res = get_arg_content(a, 0, m);

    cr_assert_not_null(res);
    free(res);
}
