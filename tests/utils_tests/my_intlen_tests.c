/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(my_intlen, basic_nbr)
{
    cr_assert(my_intlen(1) == 1);
}

Test(my_intlen_u, basic_nbr)
{
    cr_assert(my_intlen_u(1) == 1);
}
