/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "struct.h"
#include "instructions.h"
#include "test_utils.h"

Test(load_ind_instr, basic_workflow)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 10}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 2}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){3}),
        NULL
    };
    bool res = false;

    m->robots[r_id].game_infos->pc = 100;
    m->arena[112] = 0x01;
    m->arena[113] = 0x02;
    m->arena[114] = 0x03;
    m->arena[115] = 0x04;
    res = load_ind_instr(m, args, r_id);

    cr_assert(res == true);
    cr_assert_eq(m->robots[r_id].game_infos->regs[3][0], 0x01);
    cr_assert_eq(m->robots[r_id].game_infos->regs[3][1], 0x02);
    cr_assert_eq(m->robots[r_id].game_infos->regs[3][2], 0x03);
    cr_assert_eq(m->robots[r_id].game_infos->regs[3][3], 0x04);
    cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_ind_instr, test_modulo_and_carry)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_IND, REG_SIZE, (unsigned char[]){2, 0}),
        create_arg(T_IND, REG_SIZE, (unsigned char[]){0, 5}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
        NULL
    };
    load_ind_instr(m, args, r_id);

    cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(load_ind_instr, test_basic_register)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_REG, REG_SIZE, (unsigned char[]){0, 0, 0, 0}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){0, 0, 0, 1}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
        NULL
    };
    m->robots[r_id].game_infos->regs[0][3] = 10;
    m->robots[r_id].game_infos->regs[1][3] = 2;
    m->arena[12] = 0xAA;
    m->arena[13] = 0xBB;
    m->arena[14] = 0xCC;
    m->arena[15] = 0xDD;
    load_ind_instr(m, args, r_id);

    cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0xAA);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][1], 0xBB);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0xCC);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0xDD);
    cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_ind_instr, test_basic_direct)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 5}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 10}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
        NULL
    };
    m->arena[15] = 0x01;
    m->arena[16] = 0x02;
    m->arena[17] = 0x03;
    m->arena[18] = 0x04;
    load_ind_instr(m, args, r_id);

    cr_assert_eq(m->robots[r_id].game_infos->regs[1][0], 0x01);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][1], 0x02);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][2], 0x03);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][3], 0x04);
    cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_ind_instr, test_out_of_bounds)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 23, 255}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 10}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
        NULL
    };

    m->robots[r_id].game_infos->pc = 0;
    m->arena[9] = 0x01;
    m->arena[10] = 0x02;
    m->arena[11] = 0x03;
    m->arena[12] = 0x04;
    load_ind_instr(m, args, r_id);

    cr_assert_eq(m->robots[r_id].game_infos->regs[1][0], 0x01);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][1], 0x02);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][2], 0x03);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][3], 0x04);
    cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_ind_instr, test_pc_wrap)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 8}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 2}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
        NULL
    };
    m->robots[r_id].game_infos->pc = MEM_SIZE - 5;
    m->arena[5] = 0x01;
    m->arena[6] = 0x02;
    m->arena[7] = 0x03;
    m->arena[8] = 0x04;
    load_ind_instr(m, args, r_id);

    cr_assert_eq(m->robots[r_id].game_infos->regs[1][0], 0x01);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][1], 0x02);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][2], 0x03);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][3], 0x04);
    cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_ind_instr, test_zero_value)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 5}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 10}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
        NULL
    };
    m->arena[105] = 0x00;
    m->arena[106] = 0x00;
    m->arena[107] = 0x00;
    m->arena[108] = 0x00;
    bool res = load_ind_instr(m, args, r_id);

    cr_assert(res == true);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][0], 0x00);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][1], 0x00);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][2], 0x00);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][3], 0x00);
    cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(load_ind_instr, test_full_bytes)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 4}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 4}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){2}),
        NULL
    };

    m->robots[r_id].game_infos->pc = 50;
    m->arena[58] = 0xDE;
    m->arena[59] = 0xAD;
    m->arena[60] = 0xBE;
    m->arena[61] = 0xEF;
    cr_assert_eq(load_ind_instr(m, args, r_id), true);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0xDE);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][1], 0xAD);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0xBE);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0xEF);
    cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_ind_instr, dest_reg_zero)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 1}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 1}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){0}),
        NULL
    };

    m->robots[r_id].game_infos->pc = 0;
    m->arena[2] = 0x42;
    cr_assert_eq(load_ind_instr(m, args, r_id), true);
    cr_assert_eq(m->robots[r_id].game_infos->regs[0][0], 0x42);
}

Test(load_ind_instr, dest_reg_high_index)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 5}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 5}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){15}),
        NULL
    };

    m->robots[r_id].game_infos->pc = 0;
    m->arena[10] = 0x99;
    m->arena[13] = 0x77;
    cr_assert_eq(load_ind_instr(m, args, r_id), true);
    cr_assert_eq(m->robots[r_id].game_infos->regs[15][0], 0x99);
    cr_assert_eq(m->robots[r_id].game_infos->regs[15][3], 0x77);
}

Test(load_ind_instr, register_arguments)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){0}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){1}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){2}),
        NULL
    };

    m->robots[r_id].game_infos->pc = 0;
    m->robots[r_id].game_infos->regs[0][0] = 6;
    m->robots[r_id].game_infos->regs[1][0] = 4;
    m->arena[10] = 0xCA;
    m->arena[13] = 0xFE;
    cr_assert_eq(load_ind_instr(m, args, r_id), true);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0xCA);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0xFE);
}

Test(load_ind_instr, ind_arg_type)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_IND, IND_SIZE, (unsigned char[]){0, 6}),
        create_arg(T_IND, IND_SIZE, (unsigned char[]){0, 4}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){4}),
        NULL
    };

    m->robots[r_id].game_infos->pc = 100;
    m->arena[110] = 0xAA;
    m->arena[113] = 0xBB;
    cr_assert_eq(load_ind_instr(m, args, r_id), true);
}

Test(load_ind_instr, large_offset_idx_mod)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 2, 5}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 0}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){3}),
        NULL
    };

    m->robots[r_id].game_infos->pc = 0;
    m->arena[5] = 0x12;
    m->arena[8] = 0x34;
    cr_assert_eq(load_ind_instr(m, args, r_id), true);
    cr_assert_eq(m->robots[r_id].game_infos->regs[3][0], 0x12);
    cr_assert_eq(m->robots[r_id].game_infos->regs[3][3], 0x34);
}

Test(load_ind_instr, pc_at_max_minus_one)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 1}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 0}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){1}),
        NULL
    };

    m->robots[r_id].game_infos->pc = MEM_SIZE - 1;
    m->arena[0] = 0x10;
    m->arena[1] = 0x20;
    m->arena[2] = 0x30;
    m->arena[3] = 0x40;
    cr_assert_eq(load_ind_instr(m, args, r_id), true);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][0], 0x10);
    cr_assert_eq(m->robots[r_id].game_infos->regs[1][3], 0x40);
}

Test(load_ind_instr, mixed_arg_types)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){5}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 3}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){8}),
        NULL
    };

    m->robots[r_id].game_infos->pc = 0;
    m->robots[r_id].game_infos->regs[5][0] = 4;
    m->arena[7] = 0xFE;
    m->arena[10] = 0xED;
    cr_assert_eq(load_ind_instr(m, args, r_id), true);
    cr_assert_eq(m->robots[r_id].game_infos->regs[8][0], 0xFE);
    cr_assert_eq(m->robots[r_id].game_infos->regs[8][3], 0xED);
}

Test(load_ind_instr, returns_true)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 1}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 1}),
        create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){2}),
        NULL
    };

    cr_assert_eq(load_ind_instr(m, args, r_id), true);
}