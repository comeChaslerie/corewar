/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for sub_instr
*/

#include <criterion/criterion.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(sub_instr, subtracts_two_registers_into_destination)
{
    main_t *main = create_test_main(1, "Subber");
    unsigned char reg_a[1] = {1};
    unsigned char reg_b[1] = {2};
    unsigned char reg_dest[1] = {3};
    arg_t arg0 = make_arg(T_REG, 1, reg_a);
    arg_t arg1 = make_arg(T_REG, 1, reg_b);
    arg_t arg2 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    set_register_value(main, 0, 1, 5);
    set_register_value(main, 0, 2, 3);
    cr_assert(sub_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[3]), 2);
    cr_assert(!main->robots[0].game_infos->carry);
    destroy_test_main(main);
}

Test(sub_instr, zero_result_sets_carry)
{
    main_t *main = create_test_main(1, "Subber");
    unsigned char reg_a[1] = {1};
    unsigned char reg_b[1] = {2};
    unsigned char reg_dest[1] = {4};
    arg_t arg0 = make_arg(T_REG, 1, reg_a);
    arg_t arg1 = make_arg(T_REG, 1, reg_b);
    arg_t arg2 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    set_register_value(main, 0, 1, 9);
    set_register_value(main, 0, 2, 9);
    cr_assert(sub_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[4]), 0);
    cr_assert(main->robots[0].game_infos->carry);
    destroy_test_main(main);
}
