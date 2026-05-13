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
    int argc = 4;
    char *argv[4] = {"./corewar", "-dump", "0", "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 0);
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

Test(main_functions, empty_arg)
{
    int argc = 2;
    char *argv[2] = {"./corewar", ""};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, dump_no_value)
{
    int argc = 2;
    char *argv[2] = {"./corewar", "-dump"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, n_no_value)
{
    int argc = 2;
    char *argv[2] = {"./corewar", "-n"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, dump_missing_value_with_file)
{
    int argc = 3;
    char *argv[3] = {"./corewar", "-dump", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, n_missing_value_with_file)
{
    int argc = 3;
    char *argv[3] = {"./corewar", "-n", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, dump_negative_value)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "-dump", "-1", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, dump_alpha_value)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "-dump", "abc", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, n_negative_value)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "-n", "-5", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, n_alpha_value)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "-n", "abc", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, a_negative_value)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "-a", "-10", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, a_alpha_value)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "-a", "xyz", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, dump_int_max)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "-dump", "2147483647",
        "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, n_zero)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "-n", "0", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, a_zero)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "-a", "0", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, single_champion)
{
    int argc = 2;
    char *argv[2] = {"./corewar", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, two_champions)
{
    int argc = 3;
    char *argv[3] = {"./corewar", "examples/champions/abel.cor",
        "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, three_champions)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "examples/champions/abel.cor",
        "examples/champions/bill.cor", "examples/champions/pdd.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, four_champions)
{
    int argc = 5;
    char *argv[5] = {"./corewar", "examples/champions/abel.cor",
        "examples/champions/bill.cor", "examples/champions/pdd.cor",
        "examples/champions/tyron.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, same_champion_twice)
{
    int argc = 3;
    char *argv[3] = {"./corewar", "examples/champions/abel.cor",
        "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, dump_zero_two_champions)
{
    int argc = 5;
    char *argv[5] = {"./corewar", "-dump", "0", "examples/champions/abel.cor",
        "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, dump_zero_three_champions)
{
    int argc = 6;
    char *argv[6] = {"./corewar", "-dump", "0", "examples/champions/abel.cor",
        "examples/champions/bill.cor", "examples/champions/pdd.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, dump_zero_four_champions)
{
    int argc = 7;
    char *argv[7] = {"./corewar", "-dump", "0", "examples/champions/abel.cor",
        "examples/champions/bill.cor", "examples/champions/pdd.cor",
        "examples/champions/tyron.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, champion_then_dump)
{
    int argc = 4;
    char *argv[4] = {"./corewar", "examples/champions/abel.cor", "-dump", "0"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, dump_zero_no_champion)
{
    int argc = 3;
    char *argv[3] = {"./corewar", "-dump", "0"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, dump_champion_dump)
{
    int argc = 6;
    char *argv[6] = {"./corewar", "-dump", "0", "examples/champions/abel.cor",
        "-dump", "0"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, two_champions_then_dump)
{
    int argc = 5;
    char *argv[5] = {"./corewar", "examples/champions/abel.cor",
        "examples/champions/bill.cor", "-dump", "0"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, champions_dump_champion)
{
    int argc = 6;
    char *argv[6] = {"./corewar", "examples/champions/abel.cor",
        "examples/champions/bill.cor", "-dump", "0",
        "examples/champions/pdd.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, champions_two_dumps_same)
{
    int argc = 7;
    char *argv[7] = {"./corewar", "examples/champions/abel.cor",
        "examples/champions/bill.cor", "-dump", "0", "-dump", "0"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, champions_two_dumps_diff)
{
    int argc = 7;
    char *argv[7] = {"./corewar", "examples/champions/abel.cor",
        "examples/champions/bill.cor", "-dump", "0", "-dump", "100"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, n_per_champion)
{
    int argc = 13;
    char *argv[13] = {"./corewar", "-n", "4", "examples/champions/abel.cor",
        "-n", "3", "examples/champions/bill.cor", "-n", "2",
        "examples/champions/pdd.cor", "-n", "1",
        "examples/champions/tyron.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, n_per_champion_with_dump)
{
    int argc = 15;
    char *argv[15] = {"./corewar", "-n", "4", "examples/champions/abel.cor",
        "-n", "3", "examples/champions/bill.cor", "-n", "2",
        "examples/champions/pdd.cor", "-n", "1",
        "examples/champions/tyron.cor", "-dump", "0"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, dump_then_n_per_champion)
{
    int argc = 15;
    char *argv[15] = {"./corewar", "-dump", "0", "-n", "4",
        "examples/champions/abel.cor", "-n", "3",
        "examples/champions/bill.cor", "-n", "2",
        "examples/champions/pdd.cor", "-n", "1",
        "examples/champions/tyron.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, dump_n_intermixed_args)
{
    int argc = 7;
    char *argv[7] = {"./corewar", "-dump", "-n", "0", "4",
        "examples/champions/abel.cor", "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, two_dumps_one_champion)
{
    int argc = 6;
    char *argv[6] = {"./corewar", "-dump", "10", "-dump", "20",
        "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, two_n_one_champion)
{
    int argc = 6;
    char *argv[6] = {"./corewar", "-n", "1", "-n", "1",
        "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, two_a_one_champion)
{
    int argc = 6;
    char *argv[6] = {"./corewar", "-a", "100", "-a", "200",
        "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, n_champion_a_champion)
{
    int argc = 7;
    char *argv[7] = {"./corewar", "-n", "1", "examples/champions/abel.cor",
        "-a", "100", "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, champion_n_champion_a)
{
    int argc = 7;
    char *argv[7] = {"./corewar", "examples/champions/abel.cor", "-n", "2",
        "examples/champions/bill.cor", "-a", "200"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, a_champion_n_champion)
{
    int argc = 7;
    char *argv[7] = {"./corewar", "-a", "100", "examples/champions/abel.cor",
        "-n", "2", "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, dump_value_no_champion)
{
    int argc = 3;
    char *argv[3] = {"./corewar", "-dump", "10"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, fake_filename)
{
    int argc = 2;
    char *argv[2] = {"./corewar", "fake.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, real_then_fake)
{
    int argc = 3;
    char *argv[3] = {"./corewar", "examples/champions/abel.cor",
        "not_existing.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, whitespace_arg)
{
    int argc = 3;
    char *argv[3] = {"./corewar", "   ", "examples/champions/abel.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, mixed_dump_n_a_champions)
{
    int argc = 11;
    char *argv[11] = {"./corewar", "-dump", "50", "-n", "1",
        "examples/champions/abel.cor", "-a", "100", "-n", "2",
        "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}

Test(main_functions, n_a_champion_n_champion)
{
    int argc = 9;
    char *argv[9] = {"./corewar", "-n", "1", "-a", "100",
        "examples/champions/abel.cor", "-n", "1",
        "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 84);
}

Test(main_functions, n_champion_dump_n_champion)
{
    int argc = 9;
    char *argv[9] = {"./corewar", "-n", "1", "examples/champions/abel.cor",
        "-dump", "100", "-n", "2", "examples/champions/bill.cor"};

    cr_assert(main_functions(argc, argv) == 0);
}
