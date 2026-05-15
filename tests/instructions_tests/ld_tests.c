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

Test(load_instr, basic_workflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 12}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){3}),
		NULL
	};
	bool res = false;

	m->robots[r_id].game_infos->pc = 100;
	res = load_instr(m, args, r_id);

	cr_assert(res == true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][0], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][1], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][2], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][3], 0x0C);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_instr, test_full_bytes)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0xA1, 0xB2, 0xC3, 0xD4}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	load_instr(m, args, r_id);

	cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0xA1);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][1], 0xB2);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0xC3);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0xD4);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_instr, test_max_value)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0xFF, 0xFF, 0xFF, 0xFF}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		NULL
	};

	load_instr(m, args, r_id);

	cr_assert_eq(m->robots[r_id].game_infos->regs[1][0], 0xFF);
	cr_assert_eq(m->robots[r_id].game_infos->regs[1][1], 0xFF);
	cr_assert_eq(m->robots[r_id].game_infos->regs[1][2], 0xFF);
	cr_assert_eq(m->robots[r_id].game_infos->regs[1][3], 0xFF);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_instr, test_zero_value)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){4}),
		NULL
	};
	bool res = load_instr(m, args, r_id);

	cr_assert(res == true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[4][0], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[4][1], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[4][2], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->regs[4][3], 0x00);
	cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(load_instr, from_register)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){5}),
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->regs[5][0] = 0x10;
	m->robots[r_id].game_infos->regs[5][1] = 0x20;
	m->robots[r_id].game_infos->regs[5][2] = 0x30;
	m->robots[r_id].game_infos->regs[5][3] = 0x40;
	cr_assert_eq(load_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0x10);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0x40);
}

Test(load_instr, from_indirect)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_IND, IND_SIZE, (unsigned char[]){0, 8}),
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){0}),
		NULL
	};

	m->robots[r_id].game_infos->pc = 50;
	m->arena[58] = 0xAB;
	m->arena[59] = 0xCD;
	m->arena[60] = 0xEF;
	m->arena[61] = 0x01;
	cr_assert_eq(load_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[0][0], 0xAB);
	cr_assert_eq(m->robots[r_id].game_infos->regs[0][3], 0x01);
}

Test(load_instr, dest_reg_zero_index)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0xCA, 0xFE, 0xBA, 0xBE}),
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){0}),
		NULL
	};

	cr_assert_eq(load_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[0][0], 0xCA);
	cr_assert_eq(m->robots[r_id].game_infos->regs[0][3], 0xBE);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}
