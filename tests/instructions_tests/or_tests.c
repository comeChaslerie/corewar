/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for bin_or_instr
*/

#include <criterion/criterion.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(bin_or_instr, computes_bitwise_or)
{
    main_t *main = create_test_main(1, "OrBot");
    unsigned char value_a[REG_SIZE] = {0};
    unsigned char value_b[REG_SIZE] = {0};
    unsigned char reg_dest[1] = {2};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, value_a);
    arg_t arg1 = make_arg(T_DIR, DIR_SIZE, value_b);
    arg_t arg2 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    fill_u32(value_a, 5);
    fill_u32(value_b, 10);
    cr_assert(bin_or_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[2]), 15);
    cr_assert(!main->robots[0].game_infos->carry);
    destroy_test_main(main);
}

Test(bin_or_instr, mixed_reg_and_dir)
{
    main_t *main = create_test_main(1, "OrBot");
    unsigned char reg_a[1] = {1};
    unsigned char value_b[DIR_SIZE] = {0};
    unsigned char reg_dest[1] = {4};
    arg_t arg0 = make_arg(T_REG, REG_ARG_SIZE, reg_a);
    arg_t arg1 = make_arg(T_DIR, DIR_SIZE, value_b);
    arg_t arg2 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    set_register_value(main, 0, 1, 0x5);
    fill_u32(value_b, 0xA);
    cr_assert(bin_or_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[4]), 0xF);
    destroy_test_main(main);
}

Test(bin_or_instr, zero_result_sets_carry)
{
    main_t *main = create_test_main(1, "OrBot");
    unsigned char value_a[REG_SIZE] = {0};
    unsigned char value_b[REG_SIZE] = {0};
    unsigned char reg_dest[1] = {3};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, value_a);
    arg_t arg1 = make_arg(T_DIR, DIR_SIZE, value_b);
    arg_t arg2 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    fill_u32(value_a, 0);
    fill_u32(value_b, 0);
    cr_assert(bin_or_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[3]), 0);
    cr_assert(main->robots[0].game_infos->carry);
    destroy_test_main(main);
}
