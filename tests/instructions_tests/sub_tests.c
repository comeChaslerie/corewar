/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/
#include <criterion/criterion.h>
#include "struct.h"
#include "instructions.h"
#include "test_utils.h"

Test(sub_instr, basic_workflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][3] = 5;
	m->robots[r_id].game_infos->regs[1][3] = 2;
	sub_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 3);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(sub_instr, test_carry_true)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	sub_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(sub_instr, test_negative_result)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][3] = 1;
	m->robots[r_id].game_infos->regs[1][3] = 2;
	cr_assert_eq(sub_instr(m, args, r_id), true);
	cr_assert_neq(m->robots[r_id].game_infos->regs[2][3], 0x03);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(sub_instr, multi_byte_borrow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][2] = 0x01;
	m->robots[r_id].game_infos->regs[0][3] = 0x00;
	m->robots[r_id].game_infos->regs[1][3] = 0x01;
	cr_assert_eq(sub_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0xFF);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0x00);
}

Test(sub_instr, dest_register_is_source)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][3] = 10;
	m->robots[r_id].game_infos->regs[1][3] = 3;
	cr_assert_eq(sub_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[0][3], 7);
}

Test(sub_instr, equal_values_zero_result)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][3] = 50;
	m->robots[r_id].game_infos->regs[1][3] = 50;
	cr_assert_eq(sub_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0);
	cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}
