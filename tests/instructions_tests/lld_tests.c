/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for load_long_instr
*/

#include <criterion/criterion.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(load_long_instr, loads_value_without_idx_modulo)
{
    main_t *main = create_test_main(1, "LongLoadBot");
    unsigned char source[REG_SIZE] = {0};
    unsigned char reg_dest[1] = {1};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, source);
    arg_t arg1 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1};

    fill_u32(source, 520);
    set_arena_value(main, 520, 0xA1B2C3D4);
    cr_assert(load_long_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[1]), 0xA1B2C3D4);
    cr_assert(!main->robots[0].game_infos->carry);
    destroy_test_main(main);
}

Test(load_long_instr, zero_loaded_value_sets_carry)
{
    main_t *main = create_test_main(1, "LongLoadBot");
    unsigned char source[REG_SIZE] = {0};
    unsigned char reg_dest[1] = {2};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, source);
    arg_t arg1 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1};

    fill_u32(source, 4);
    cr_assert(load_long_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[2]), 0);
    cr_assert(main->robots[0].game_infos->carry);
    destroy_test_main(main);
}
