/*
** EPITECH PROJECT, 2026
** project
** File description:
** tests for live_instr
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
    unsigned char buf[4] = {0, 0, 0, 1};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    bool result = live_instr(&m, args, 0);

    cr_assert(result);
    cr_assert_stdout_eq_str("The player 1(TestBot) is alive.\n");
    free(m.robots);
}

Test(live_instr, robot_found_sets_live)
{
    main_t m = make_main(1, "TestBot", 1);
    unsigned char buf[4] = {0, 0, 0, 1};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    live_instr(&m, args, 0);

    cr_assert(m.robots[0].live);
    free(m.robots);
}

Test(live_instr, robot_found_increments_nb_live)
{
    main_t m = make_main(1, "TestBot", 1);
    unsigned char buf[4] = {0, 0, 0, 1};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    live_instr(&m, args, 0);

    cr_assert_eq(m.nb_live, 1);
    free(m.robots);
}

Test(live_instr, robot_not_found_returns_true, .init = cr_redirect_stdout)
{
    main_t m = make_main(1, "TestBot", 1);
    unsigned char buf[4] = {0, 0, 0, 99};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    bool result = live_instr(&m, args, 0);

    cr_assert(result);
    cr_assert_stdout_eq_str("");
    free(m.robots);
}

Test(live_instr, robot_not_found_nb_live_unchanged)
{
    main_t m = make_main(1, "TestBot", 1);
    unsigned char buf[4] = {0, 0, 0, 99};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    live_instr(&m, args, 0);

    cr_assert_eq(m.nb_live, 0);
    free(m.robots);
}

Test(live_instr, robot_not_found_live_unchanged)
{
    main_t m = make_main(1, "TestBot", 1);
    unsigned char buf[4] = {0, 0, 0, 99};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    live_instr(&m, args, 0);

    cr_assert(!m.robots[0].live);
    free(m.robots);
}

Test(live_instr, multiple_robots_correct_one_found, .init = cr_redirect_stdout)
{
    main_t m = {0};
    m.nbr_robots = 3;
    m.nb_live = 0;
    m.robots = malloc(sizeof(robot_infos_t) * 3);
    m.robots[0].id = 1;
    m.robots[0].live = false;
    my_strcpy(m.robots[0].header.prog_name, "BotA");
    m.robots[1].id = 2;
    m.robots[1].live = false;
    my_strcpy(m.robots[1].header.prog_name, "BotB");
    m.robots[2].id = 3;
    m.robots[2].live = false;
    my_strcpy(m.robots[2].header.prog_name, "BotC");

    unsigned char buf[4] = {0, 0, 0, 2};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    live_instr(&m, args, 0);

    cr_assert(m.robots[1].live);
    cr_assert(!m.robots[0].live);
    cr_assert(!m.robots[2].live);
    cr_assert_eq(m.nb_live, 1);
    free(m.robots);
}

Test(live_instr, multiple_robots_correct_output, .init = cr_redirect_stdout)
{
    main_t m = {0};
    m.nbr_robots = 3;
    m.nb_live = 0;
    m.robots = malloc(sizeof(robot_infos_t) * 3);
    m.robots[0].id = 1;
    my_strcpy(m.robots[0].header.prog_name, "BotA");
    m.robots[1].id = 2;
    my_strcpy(m.robots[1].header.prog_name, "BotB");
    m.robots[2].id = 3;
    my_strcpy(m.robots[2].header.prog_name, "BotC");

    unsigned char buf[4] = {0, 0, 0, 2};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    live_instr(&m, args, 0);

    cr_assert_stdout_eq_str("The player 2(BotB) is alive.\n");
    free(m.robots);
}

Test(live_instr, called_twice_nb_live_is_two)
{
    main_t m = make_main(1, "TestBot", 1);
    unsigned char buf[4] = {0, 0, 0, 1};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    live_instr(&m, args, 0);
    live_instr(&m, args, 0);

    cr_assert_eq(m.nb_live, 2);
    free(m.robots);
}

Test(live_instr, zero_robots_returns_true)
{
    main_t m = {0};
    m.nbr_robots = 0;
    m.robots = NULL;

    unsigned char buf[4] = {0, 0, 0, 1};
    arg_t arg0 = {.arg = buf, .size = 4};
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    bool result = live_instr(&m, args, 0);

    cr_assert(result);
}
