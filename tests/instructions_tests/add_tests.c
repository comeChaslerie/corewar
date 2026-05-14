/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for add_instr
*/

#include <criterion/criterion.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(add_instr, sums_two_registers_into_destination)
{
    main_t *main = create_test_main(1, "Adder");
    unsigned char reg_a[1] = {1};
    unsigned char reg_b[1] = {2};
    unsigned char reg_dest[1] = {3};
    arg_t arg0 = make_arg(T_REG, 1, reg_a);
    arg_t arg1 = make_arg(T_REG, 1, reg_b);
    arg_t arg2 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    set_register_value(main, 0, 1, 1);
    set_register_value(main, 0, 2, 2);
    cr_assert(add_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[3]), 3);
    cr_assert(!main->robots[0].game_infos->carry);
    destroy_test_main(main);
}

Test(add_instr, zero_result_sets_carry)
{
    main_t *main = create_test_main(1, "Adder");
    unsigned char reg_a[1] = {1};
    unsigned char reg_b[1] = {2};
    unsigned char reg_dest[1] = {4};
    arg_t arg0 = make_arg(T_REG, 1, reg_a);
    arg_t arg1 = make_arg(T_REG, 1, reg_b);
    arg_t arg2 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    set_register_value(main, 0, 1, 0);
    set_register_value(main, 0, 2, 0);
    cr_assert(add_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[4]), 0);
    cr_assert(main->robots[0].game_infos->carry);
    destroy_test_main(main);
}
