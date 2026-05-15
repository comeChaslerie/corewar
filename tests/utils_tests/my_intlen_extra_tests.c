/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_intlen edge cases
*/
#include <criterion/criterion.h>
#include "utils.h"

Test(my_intlen, zero)
{
    cr_assert_eq(my_intlen(0), 1);
}

Test(my_intlen, single_digit)
{
    cr_assert_eq(my_intlen(7), 1);
}

Test(my_intlen, two_digits)
{
    cr_assert_eq(my_intlen(42), 2);
}

Test(my_intlen, negative_single)
{
    cr_assert_eq(my_intlen(-7), 2);
}

Test(my_intlen, negative_large)
{
    cr_assert_eq(my_intlen(-12345), 6);
}

Test(my_intlen, large_positive)
{
    cr_assert_eq(my_intlen(123456789), 9);
}

Test(my_intlen, int_max)
{
    cr_assert_eq(my_intlen(2147483647), 10);
}

Test(my_intlen_u, zero)
{
    cr_assert_eq(my_intlen_u(0), 1);
}

Test(my_intlen_u, single_digit)
{
    cr_assert_eq(my_intlen_u(7), 1);
}

Test(my_intlen_u, two_digits)
{
    cr_assert_eq(my_intlen_u(42), 2);
}

Test(my_intlen_u, large)
{
    cr_assert_eq(my_intlen_u(123456789), 9);
}

Test(my_intlen_u, max_unsigned)
{
    cr_assert_eq(my_intlen_u(4294967295u), 10);
}
