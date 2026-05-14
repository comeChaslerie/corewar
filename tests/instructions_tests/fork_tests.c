/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/
#include <criterion/criterion.h>
#include "struct.h"
#include "instructions.h"
#include "define.h"
#include "test_utils.h"

Test(fork_instr, basic_workflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 42}),
		NULL
	};
	bool res = false;

	m->robots[r_id].game_infos->pc = 100;
	res = fork_instr(m, args, r_id);

	cr_assert(res == true);
	cr_assert_not_null(m->robots[r_id].child);
	cr_assert_eq(m->robots[r_id].child->game_infos->pc, 100 + (42 % IDX_MOD));
}

Test(fork_instr, test_modulo)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 2, 5}),
		NULL
	};

	fork_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].child->game_infos->pc, 5);
}

Test(fork_instr, test_chain_children)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args_a[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 10}),
		NULL
	};
	arg_t *args_b[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 20}),
		NULL
	};

	fork_instr(m, args_a, r_id);
	fork_instr(m, args_b, r_id);
	cr_assert_not_null(m->robots[r_id].child);
	cr_assert_not_null(m->robots[r_id].child->child);
	cr_assert_eq(m->robots[r_id].child->child->game_infos->pc, 20);
}
