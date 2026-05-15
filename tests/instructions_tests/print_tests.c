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

Test(print_instr, basic_workflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0x41, 0x42, 0x43, 0x44}),
		NULL
	};
	bool res = print_instr(m, args, r_id);

	cr_assert(res == true);
}

Test(print_instr, test_zero_value)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0x00, 0x00, 0x00, 0x00}),
		NULL
	};

	cr_assert_eq(print_instr(m, args, r_id), true);
}

Test(print_instr, with_reg_type)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_REG, REG_ARG_SIZE, (unsigned char[]){2}),
		NULL
	};

	m->robots[r_id].game_infos->regs[2][0] = 'A';
	m->robots[r_id].game_infos->regs[2][1] = 'B';
	m->robots[r_id].game_infos->regs[2][2] = 'C';
	m->robots[r_id].game_infos->regs[2][3] = 'D';
	cr_assert_eq(print_instr(m, args, r_id), true);
}

Test(print_instr, with_ind_type)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_IND, IND_SIZE, (unsigned char[]){0, 5}),
		NULL
	};

	m->robots[r_id].game_infos->pc = 100;
	m->arena[105] = 'X';
	cr_assert_eq(print_instr(m, args, r_id), true);
}

Test(print_instr, all_max_bytes)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0xFF, 0xFF, 0xFF, 0xFF}),
		NULL
	};

	cr_assert_eq(print_instr(m, args, r_id), true);
}
