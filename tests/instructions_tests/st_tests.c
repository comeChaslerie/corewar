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

Test(store_instr, basic_register_workflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){3}),
		NULL
	};

	m->robots[r_id].game_infos->regs[0][0] = 0xAA;
	m->robots[r_id].game_infos->regs[0][1] = 0xBB;
	m->robots[r_id].game_infos->regs[0][2] = 0xCC;
	m->robots[r_id].game_infos->regs[0][3] = 0xDD;
	store_instr(m, args, r_id);

	cr_assert_eq(m->robots[r_id].game_infos->regs[3][0], 0xAA);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][1], 0xBB);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][2], 0xCC);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][3], 0xDD);
}

Test(store_instr, test_memory_workflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		create_arg(T_IND, IND_SIZE, (unsigned char[]){0, 12}),
		NULL
	};

	m->robots[r_id].game_infos->pc = 100;
	m->robots[r_id].game_infos->regs[2][0] = 0x01;
	m->robots[r_id].game_infos->regs[2][1] = 0x02;
	m->robots[r_id].game_infos->regs[2][2] = 0x03;
	m->robots[r_id].game_infos->regs[2][3] = 0x04;
	store_instr(m, args, r_id);

	cr_assert_eq(m->arena[112], 0x01);
	cr_assert_eq(m->arena[113], 0x02);
	cr_assert_eq(m->arena[114], 0x03);
	cr_assert_eq(m->arena[115], 0x04);
}

Test(store_instr, test_out_of_bounds)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		create_arg(T_IND, IND_SIZE, (unsigned char[]){0, 4}),
		NULL
	};

	m->robots[r_id].game_infos->pc = MEM_SIZE - 2;
	m->robots[r_id].game_infos->regs[1][0] = 0x10;
	m->robots[r_id].game_infos->regs[1][1] = 0x20;
	m->robots[r_id].game_infos->regs[1][2] = 0x30;
	m->robots[r_id].game_infos->regs[1][3] = 0x40;
	store_instr(m, args, r_id);

	cr_assert_eq(m->arena[2], 0x10);
	cr_assert_eq(m->arena[3], 0x20);
	cr_assert_eq(m->arena[4], 0x30);
	cr_assert_eq(m->arena[5], 0x40);
}

Test(store_instr, indirect_pc_zero)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){4}),
		create_arg(T_IND, IND_SIZE, (unsigned char[]){0, 50}),
		NULL
	};

	m->robots[r_id].game_infos->regs[4][0] = 0x99;
	m->robots[r_id].game_infos->regs[4][3] = 0x66;
	cr_assert_eq(store_instr(m, args, r_id), true);
	cr_assert_eq(m->arena[50], 0x99);
	cr_assert_eq(m->arena[53], 0x66);
}

Test(store_instr, register_to_register_overwrites)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){5}),
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){5}),
		NULL
	};

	m->robots[r_id].game_infos->regs[5][0] = 0x12;
	m->robots[r_id].game_infos->regs[5][3] = 0x34;
	cr_assert_eq(store_instr(m, args, r_id), true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[5][0], 0x12);
	cr_assert_eq(m->robots[r_id].game_infos->regs[5][3], 0x34);
}

Test(store_instr, all_zero_register)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){0}),
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){1}),
		NULL
	};

	cr_assert_eq(store_instr(m, args, r_id), true);
	for (int i = 0; i < REG_SIZE; i++)
		cr_assert_eq(m->robots[r_id].game_infos->regs[1][i], 0);
}
