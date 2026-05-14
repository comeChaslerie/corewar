/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for jump_instr
*/

#include <criterion/criterion.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(jump_instr, updates_pc_only_when_carry_is_set)
{
    main_t *main = create_test_main(1, "JumpBot");
    unsigned char offset[REG_SIZE] = {0};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, offset);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    fill_u32(offset, 600);
    main->robots[0].game_infos->pc = 100;
    main->robots[0].game_infos->carry = true;
    cr_assert(jump_instr(main, args, 0));
    cr_assert_eq(main->robots[0].game_infos->pc, 100 + (600 % IDX_MOD));
    destroy_test_main(main);
}

Test(jump_instr, leaves_pc_unchanged_when_carry_is_clear)
{
    main_t *main = create_test_main(1, "JumpBot");
    unsigned char offset[REG_SIZE] = {0};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, offset);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    fill_u32(offset, 600);
    main->robots[0].game_infos->pc = 100;
    main->robots[0].game_infos->carry = false;
    cr_assert(jump_instr(main, args, 0));
    cr_assert_eq(main->robots[0].game_infos->pc, 100);
    destroy_test_main(main);
}
