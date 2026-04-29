/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** is_nbr tests
*/
#include <criterion/criterion.h>
#include "utils.h"


Test(is_nbr, basic_nbr)
{
    cr_assert(is_nbr("12") == true);
}

Test(is_nbr, edge_case_nbr)
{
    cr_assert(is_nbr("90") == true);
}

Test(is_nbr, not_a_nbr)
{
    cr_assert(is_nbr("ab") == false);
}

Test(is_nbr, both_a_nbr_and_a_str)
{
    cr_assert(is_nbr("a20b") == false);
}

Test(is_nbr, negative_nbr)
{
    cr_assert(is_nbr("-12") == false);
}
