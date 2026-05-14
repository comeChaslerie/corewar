/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <criterion/criterion.h>
#include <string.h>
#include "struct.h"
#include "instructions.h"
#include "test_utils.h"

Test(live_instr, basic_workflow)
{
	unsigned int r_id = 0;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 42}),
		NULL
	};

	m->nbr_robots = 2;
	m->robots[0].id = 42;
	strcpy(m->robots[0].header.prog_name, "bot_a");
	m->robots[1].id = 84;
	strcpy(m->robots[1].header.prog_name, "bot_b");

	live_instr(m, args, r_id);
	cr_assert_eq(m->robots[0].live, true);
	cr_assert_eq(m->nb_live, 1);
}

Test(live_instr, test_unknown_player)
{
	unsigned int r_id = 0;
	main_t *m = init_test_env(r_id);
	arg_t *args[MAX_ARGS_NUMBER] = {
		create_arg(T_DIR, REG_SIZE, (unsigned char[]){0, 0, 0, 99}),
		NULL
	};

	m->nbr_robots = 2;
	m->robots[0].id = 42;
	strcpy(m->robots[0].header.prog_name, "bot_a");
	m->robots[1].id = 84;
	strcpy(m->robots[1].header.prog_name, "bot_b");

	live_instr(m, args, r_id);
	cr_assert_eq(m->robots[0].live, false);
	cr_assert_eq(m->robots[1].live, false);
	cr_assert_eq(m->nb_live, 0);
}

