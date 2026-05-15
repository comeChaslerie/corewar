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

Test(jump_instr, basic_workflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 2, 0}),
		NULL
	};

	m->robots[r_id].game_infos->pc = 100;
	m->robots[r_id].game_infos->carry = true;
	jump_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->pc, 100 + (512 % IDX_MOD));
}

Test(jump_instr, test_carry_false)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 30}),
		NULL
	};

	m->robots[r_id].game_infos->pc = 100;
	m->robots[r_id].game_infos->carry = false;
	jump_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->pc, 100);
}

Test(jump_instr, test_modulo)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 3, 0}),
		NULL
	};

	m->robots[r_id].game_infos->carry = true;
	jump_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->pc, (768 % IDX_MOD));
}

Test(jump_instr, no_carry_pc_unchanged)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 30}),
		NULL
	};

	m->robots[r_id].game_infos->pc = 200;
	m->robots[r_id].game_infos->carry = false;
	cr_assert_eq(jump_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->pc, 200);
}

Test(jump_instr, returns_true_when_jump)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 5}),
		NULL
	};

	m->robots[r_id].game_infos->pc = 0;
	m->robots[r_id].game_infos->carry = true;
	cr_assert_eq(jump_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->pc, 5);
}

Test(jump_instr, zero_offset_with_carry)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 0}),
		NULL
	};

	m->robots[r_id].game_infos->pc = 50;
	m->robots[r_id].game_infos->carry = true;
	cr_assert_eq(jump_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->pc, 50);
}
