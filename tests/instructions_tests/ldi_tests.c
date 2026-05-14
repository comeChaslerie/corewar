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
    unsigned int r_id = 0;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_IND, 2, (unsigned char[]){0, 10}),
        create_arg(T_IND, 2, (unsigned char[]){0, 2}),
        create_arg(T_REG, 1, (unsigned char[]){3}),
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
    cr_assert_eq(m->robots[r_id].game_infos->regs[3][3], 0x04);
    cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_ind_instr, test_modulo_and_carry)
{
    unsigned int r_id = 0;
    main_t *m = init_test_env(r_id);
    arg_t *args[MAX_ARGS_NUMBER] = {
        create_arg(T_IND, 2, (unsigned char[]){2, 0}),
        create_arg(T_IND, 2, (unsigned char[]){0, 5}),
        create_arg(T_REG, 1, (unsigned char[]){1}),
        NULL
    };
    load_ind_instr(m, args, r_id);

    cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(load_ind_instr, test_)