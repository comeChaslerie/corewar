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

Test(add_instr, basic_workflow)
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
	add_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 3);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(add_instr, test_carry_true)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	add_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(add_instr, test_overflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][0] = 0xFF;
	m->robots[r_id].game_infos->regs[0][1] = 0xFF;
	m->robots[r_id].game_infos->regs[0][2] = 0xFF;
	m->robots[r_id].game_infos->regs[0][3] = 0xFF;
	m->robots[r_id].game_infos->regs[1][3] = 1;
	add_instr(m, args, r_id);

	cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][1], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(add_instr, multi_byte_carry_chain)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][2] = 0xFF;
	m->robots[r_id].game_infos->regs[0][3] = 0xFF;
	m->robots[r_id].game_infos->regs[1][3] = 0x01;
	cr_assert_eq(add_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][1], 0x01);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0x00);
}

Test(add_instr, high_byte_addition)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][0] = 0x10;
	m->robots[r_id].game_infos->regs[1][0] = 0x20;
	cr_assert_eq(add_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0x30);
}

Test(add_instr, dest_register_is_source)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][3] = 5;
	m->robots[r_id].game_infos->regs[1][3] = 7;
	cr_assert_eq(add_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[0][3], 12);
}
