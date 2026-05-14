/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for store_ind_instr
*/

#include <criterion/criterion.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(store_ind_instr, stores_register_into_arena_with_two_offsets)
{
    main_t *main = create_test_main(1, "StiBot");
    unsigned char reg_src[1] = {1};
    unsigned char value_a[REG_SIZE] = {0};
    unsigned char value_b[REG_SIZE] = {0};
    arg_t arg0 = make_arg(T_REG, 1, reg_src);
    arg_t arg1 = make_arg(T_DIR, DIR_SIZE, value_a);
    arg_t arg2 = make_arg(T_DIR, DIR_SIZE, value_b);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    fill_u32(value_a, 5);
    fill_u32(value_b, 7);
    main->robots[0].game_infos->pc = 10;
    set_register_value(main, 0, 1, 0xAABBCCDD);
    cr_assert(store_ind_instr(main, args, 0));
    cr_assert_eq(read_u32(&main->arena[22]), 0xAABBCCDD);
    destroy_test_main(main);
}

Test(store_ind_instr, writes_at_wrapped_address)
{
    main_t *main = create_test_main(1, "StiBot");
    unsigned char reg_src[1] = {1};
    unsigned char value_a[REG_SIZE] = {0};
    unsigned char value_b[REG_SIZE] = {0};
    arg_t arg0 = make_arg(T_REG, 1, reg_src);
    arg_t arg1 = make_arg(T_DIR, DIR_SIZE, value_a);
    arg_t arg2 = make_arg(T_DIR, DIR_SIZE, value_b);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    fill_u32(value_a, 600);
    fill_u32(value_b, 0);
    main->robots[0].game_infos->pc = 1;
    set_register_value(main, 0, 1, 0x01020304);
    cr_assert(store_ind_instr(main, args, 0));
    cr_assert_eq(read_u32(&main->arena[89]), 0x01020304);
    destroy_test_main(main);
}
