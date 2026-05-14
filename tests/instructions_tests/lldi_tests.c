/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for load_long_ind_instr
*/

#include <criterion/criterion.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(load_long_ind_instr, loads_value_without_idx_modulo)
{
    main_t *main = create_test_main(1, "LldiBot");
    unsigned char value_a[REG_SIZE] = {0};
    unsigned char value_b[REG_SIZE] = {0};
    unsigned char reg_dest[1] = {1};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, value_a);
    arg_t arg1 = make_arg(T_DIR, DIR_SIZE, value_b);
    arg_t arg2 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    fill_u32(value_a, 300);
    fill_u32(value_b, 400);
    set_arena_value(main, 700, 0xCAFEBABE);
    cr_assert(load_long_ind_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[1]), 0xCAFEBABE);
    cr_assert(!main->robots[0].game_infos->carry);
    destroy_test_main(main);
}

Test(load_long_ind_instr, zero_loaded_value_sets_carry)
{
    main_t *main = create_test_main(1, "LldiBot");
    unsigned char value_a[REG_SIZE] = {0};
    unsigned char value_b[REG_SIZE] = {0};
    unsigned char reg_dest[1] = {2};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, value_a);
    arg_t arg1 = make_arg(T_DIR, DIR_SIZE, value_b);
    arg_t arg2 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1, &arg2};

    fill_u32(value_a, 4);
    fill_u32(value_b, 0);
    cr_assert(load_long_ind_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[2]), 0);
    cr_assert(main->robots[0].game_infos->carry);
    destroy_test_main(main);
}
