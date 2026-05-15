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

Test(bin_or_instr, basic_workflow)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0xF0, 0x00, 0xF0, 0x00}),
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0x0F, 0x0F, 0x0F, 0x0F}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){2}),
		NULL
	};

	bin_or_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][0], 0xFF);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][1], 0x0F);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][2], 0xFF);
	cr_assert_eq(m->robots[r_id].game_infos->regs[2][3], 0x0F);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(bin_or_instr, test_zero_value)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0x00, 0x00, 0x00, 0x00}),
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0x00, 0x00, 0x00, 0x00}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){1}),
		NULL
	};

	bin_or_instr(m, args, r_id);
	cr_assert_eq(m->robots[r_id].game_infos->carry, true);
}

Test(bin_or_instr, full_mask)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0xFF, 0xFF, 0xFF, 0xFF}),
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0x00, 0x00, 0x00, 0x00}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){0}),
		NULL
	};

	cr_assert_eq(bin_or_instr(m, args, r_id), true);
	for (int i = 0; i < REG_SIZE; i++)
		cr_assert_eq(m->robots[r_id].game_infos->regs[0][i], 0xFF);
	cr_assert_eq(m->robots[r_id].game_infos->carry, false);
}

Test(bin_or_instr, returns_true)
{
	unsigned int r_id = 1;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0x55, 0x55, 0x55, 0x55}),
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0xAA, 0xAA, 0xAA, 0xAA}),
		create_arg(T_REG, REG_SIZE, (unsigned char[]){3}),
		NULL
	};

	cr_assert_eq(bin_or_instr(m, args, r_id), true);
	for (int i = 0; i < REG_SIZE; i++)
		cr_assert_eq(m->robots[r_id].game_infos->regs[3][i], 0xFF);
}
