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
        create_arg(T_REG, REG_SIZE, (unsigned char[]){0, 0, 0, 10}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){0, 0, 0, 2}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){0, 0, 0, 3}),
        NULL
    };
    m->robots[r_id].game_infos->regs[0][0] = 0x01;
    m->robots[r_id].game_infos->regs[0][1] = 0x02;
    m->robots[r_id].game_infos->regs[0][2] = 0x03;
    load_ind_instr(m, args, r_id);

    cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0x01);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][1], 0x02);
    cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0x03);
    cr_assert_eq(m->robots[r_id].game_infos->carry, true);
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
    m->arena[105] = 0x01;
    m->arena[106] = 0x02;
    m->arena[107] = 0x03;
    m->arena[108] = 0x04;
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
    cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(load_ind_instr, test_negative_offset)
{
    unsigned int r_id = 1;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 250}),
        create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 10}),
        create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
        NULL
    };
    m->robots[r_id].game_infos->pc = 5;
    m->arena[MEM_SIZE - 1] = 0x01;
    m->arena[0] = 0x02;
    m->arena[1] = 0x03;
    m->arena[2] = 0x04;
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