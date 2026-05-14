/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for fork_long_instr
*/

#include <criterion/criterion.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(fork_long_instr, creates_child_without_idx_modulo)
{
    main_t *main = create_test_main(1, "LforkBot");
    unsigned char offset[REG_SIZE] = {0};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, offset);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    fill_u32(offset, 600);
    main->robots[0].game_infos->pc = 42;
    cr_assert(fork_long_instr(main, args, 0));
    cr_assert(main->robots[0].child);
    cr_assert_eq(main->robots[0].child->game_infos->pc, 642);
    cr_assert_eq(main->robots[0].game_infos->pc, 42);
    destroy_test_main(main);
}

Test(fork_long_instr, returns_true_when_robot_already_has_parent)
{
    main_t *main = create_test_main(1, "LforkBot");
    unsigned char offset[REG_SIZE] = {0};
    arg_t arg0 = make_arg(T_DIR, DIR_SIZE, offset);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    main->robots[0].parent = &main->robots[0];
    fill_u32(offset, 20);
    cr_assert(fork_long_instr(main, args, 0));
    cr_assert(!main->robots[0].child);
    destroy_test_main(main);
}
