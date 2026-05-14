/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "utils.h"
#include "define.h"
#include "instructions.h"
#include "struct.h"

static main_t make_main(unsigned int id, const char *name, unsigned int nbr_robots)
{
    main_t m = {0};
    m.nbr_robots = nbr_robots;
    m.nb_live = 0;
    m.robots = malloc(sizeof(robot_infos_t) * nbr_robots);
    m.robots[0].id = id;
    m.robots[0].live = false;
    my_strcpy(m.robots[0].header.prog_name, name);
    return m;
}

Test(live_instr, robot_found_returns_true, .init = cr_redirect_stdout)
{
    main_t m = make_main(1, "TestBot", 1);
    arg_t arg0 = {.arg = {0, 0, 0, 1}, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    bool result = live_instr(&m, args, 0);

    cr_assert(result);
    cr_assert_stdout_eq_str("The player 1(TestBot) is alive.\n");
    free(m.robots);
}

Test(live_instr, robot_not_found_no_output, .init = cr_redirect_stdout)
{
    main_t m = make_main(1, "TestBot", 1);
    arg_t arg0 = {.arg = {0, 0, 0, 99}, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    bool result = live_instr(&m, args, 0);

    cr_assert(result);
    cr_assert_stdout_eq_str("");
    free(m.robots);
}
