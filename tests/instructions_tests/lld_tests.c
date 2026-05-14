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

Test(load_long_instr, basic_workflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 12}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){3}),
		NULL
	};

	m->robots[r_id].game_infos->pc = 100;
	m->arena[112] = 0x11;
	m->arena[113] = 0x22;
	m->arena[114] = 0x33;
	m->arena[115] = 0x44;
	load_long_instr(m, args, r_id);

	cr_assert_eq(m->robots[r_id].game_infos->regs[3][0], 0x11);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][1], 0x22);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][2], 0x33);
	cr_assert_eq(m->robots[r_id].game_infos->regs[3][3], 0x44);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(load_long_instr, test_no_modulo)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 2, 5}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		NULL
	};

	m->arena[517] = 0xDE;
	m->arena[518] = 0xAD;
	m->arena[519] = 0xBE;
	m->arena[520] = 0xEF;
	load_long_instr(m, args, r_id);

	cr_assert_eq(m->robots[r_id].game_infos->regs[0][0], 0xDE);
	cr_assert_eq(m->robots[r_id].game_infos->regs[0][1], 0xAD);
	cr_assert_eq(m->robots[r_id].game_infos->regs[0][2], 0xBE);
	cr_assert_eq(m->robots[r_id].game_infos->regs[0][3], 0xEF);
}

Test(load_long_instr, test_out_of_bounds)
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
	load_long_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0xA1);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][1], 0xB2);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0xC3);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0xD4);
}

Test(load_long_instr, test_zero_value)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 10}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){4}),
		NULL
	};

	load_long_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}
