/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_getnbr tests
*/
#include <criterion/criterion.h>
#include "utils.h"


Test(my_getnbr, basic_nbr)
{
    int nbr = my_getnbr("12", 0);

    cr_assert(nbr == 12);
}

Test(my_getnbr, basic_nbr_with_different_start)
{
    int nbr = my_getnbr("1234", 2);

    cr_assert(nbr == 34);
}

Test(my_getnbr, nbr_with_letter)
{
    int nbr = my_getnbr("12a34", 0);

    cr_assert(nbr == 12);
}

Test(my_getnbr, negative_nbr)
{
    int nbr = my_getnbr("-12", 0);

    cr_assert(nbr == -12);
}

Test(my_getnbr, nbr_after_letters)
{
    int nbr = my_getnbr("ae20", 0);

    cr_assert(nbr == 20);
}

Test(my_getnbr, no_nbr)
{
    int nbr = my_getnbr("ae", 0);

    cr_assert(nbr == 0);
}