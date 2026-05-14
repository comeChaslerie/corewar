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
	m->arena[112] = 0x01;
	m->arena[113] = 0x02;
	m->arena[114] = 0x03;
	m->arena[115] = 0x04;
	res = load_instr(m, args, r_id);

	cr_assert(res == true);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][0], 0x01);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][1], 0x02);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][2], 0x03);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][3], 0x04);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_instr, test_modulo_and_carry)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 2, 5}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		NULL
	};

	m->arena[5] = 0x00;
	m->arena[6] = 0x00;
	m->arena[7] = 0x00;
	m->arena[8] = 0x00;
	load_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(load_instr, test_out_of_bounds)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 4}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->pc = MEM_SIZE - 2;
	m->arena[2] = 0xA1;
	m->arena[3] = 0xB2;
	m->arena[4] = 0xC3;
	m->arena[5] = 0xD4;
	load_instr(m, args, r_id);

	cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0xA1);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][1], 0xB2);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0xC3);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0xD4);
}

Test(load_instr, test_zero_value)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 10}),
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
