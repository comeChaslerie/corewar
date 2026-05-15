/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_put_nbr tests
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

int my_put_nbr(int n);

Test(my_put_nbr, zero, .init = cr_redirect_stdout)
{
    my_put_nbr(0);
    fflush(stdout);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr, one, .init = cr_redirect_stdout)
{
    my_put_nbr(1);
    fflush(stdout);
    cr_assert_stdout_eq_str("1");
}

Test(my_put_nbr, positive_basic, .init = cr_redirect_stdout)
{
    my_put_nbr(42);
    fflush(stdout);
    cr_assert_stdout_eq_str("42");
}

Test(my_put_nbr, large_positive, .init = cr_redirect_stdout)
{
    my_put_nbr(123456);
    fflush(stdout);
    cr_assert_stdout_eq_str("123456");
}

Test(my_put_nbr, int_max, .init = cr_redirect_stdout)
{
    my_put_nbr(2147483647);
    fflush(stdout);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_put_nbr, negative_basic, .init = cr_redirect_stdout)
{
    my_put_nbr(-42);
    fflush(stdout);
    cr_assert_stdout_eq_str("-42");
}

Test(my_put_nbr, negative_one, .init = cr_redirect_stdout)
{
    my_put_nbr(-1);
    fflush(stdout);
    cr_assert_stdout_eq_str("-1");
}

Test(my_put_nbr, int_min, .init = cr_redirect_stdout)
{
    my_put_nbr(-2147483648);
    fflush(stdout);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_put_nbr, return_value)
{
    cr_assert_eq(my_put_nbr(0), 0);
    cr_assert_eq(my_put_nbr(42), 0);
    cr_assert_eq(my_put_nbr(-2147483648), 0);
}

Test(my_put_nbr_u, zero, .init = cr_redirect_stdout)
{
    my_put_nbr_u(0);
    fflush(stdout);
    cr_assert_stdout_eq_str("");
}

Test(my_put_nbr_u, basic, .init = cr_redirect_stdout)
{
    my_put_nbr_u(42);
    fflush(stdout);
    cr_assert_stdout_eq_str("42");
}

Test(my_put_nbr_u, large, .init = cr_redirect_stdout)
{
    my_put_nbr_u(4294967295u);
    fflush(stdout);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_put_nbr_u, single_digit, .init = cr_redirect_stdout)
{
    my_put_nbr_u(7);
    fflush(stdout);
    cr_assert_stdout_eq_str("7");
}

Test(my_put_nbr_u, return_value)
{
    cr_assert_eq(my_put_nbr_u(0), 0);
    cr_assert_eq(my_put_nbr_u(42), 0);
}
