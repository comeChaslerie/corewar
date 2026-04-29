/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main_functions tests
*/
#include <criterion/criterion.h>
#include "handle_main.h"


Test(main_functions, basic_args)
{
    int argc = 2;
    char *argv[2] = {"./corewar", "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 84); //should return 0
}


Test(main_functions, basic_wrong_args)
{
    int argc = 2;
    char *argv[2] = {"./corewar", "-a"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, basic_file_args)
{
    int argc = 3;
    char *argv[3] = {"./corewar", "file", "file1"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, full_args)
{
    int argc = 11;
    char *argv[11] = {"./corewar", "-dump", "200", "-a", "168",
        "-n", "2", "examples/champions/bill.cor", "-n", "1", "examples/champions/pdd.cor"};

    cr_assert(main_functions(argc, argv) == 84); //should return 0
}