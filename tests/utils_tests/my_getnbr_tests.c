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

Test(my_getnbr, null_string)
{
    cr_assert(my_getnbr(NULL, 0) == 0);
}

Test(my_getnbr, negative_start)
{
    cr_assert(my_getnbr("123", -1) == 0);
}

Test(my_getnbr, empty_string)
{
    cr_assert(my_getnbr("", 0) == 0);
}

Test(my_getnbr, single_digit)
{
    cr_assert(my_getnbr("7", 0) == 7);
}

Test(my_getnbr, zero)
{
    cr_assert(my_getnbr("0", 0) == 0);
}

Test(my_getnbr, large_number)
{
    cr_assert(my_getnbr("123456", 0) == 123456);
}

Test(my_getnbr, int_max)
{
    cr_assert(my_getnbr("2147483647", 0) == 2147483647);
}

Test(my_getnbr, int_min)
{
    cr_assert(my_getnbr("-2147483648", 0) == -2147483648);
}

Test(my_getnbr, overflow_positive)
{
    cr_assert(my_getnbr("2147483648", 0) == 0);
}

Test(my_getnbr, overflow_negative)
{
    cr_assert(my_getnbr("-2147483649", 0) == 0);
}

Test(my_getnbr, plus_sign)
{
    cr_assert(my_getnbr("+42", 0) == 42);
}

Test(my_getnbr, double_negative)
{
    cr_assert(my_getnbr("--42", 0) == 42);
}

Test(my_getnbr, triple_negative)
{
    cr_assert(my_getnbr("---42", 0) == -42);
}

Test(my_getnbr, leading_letters_with_negative)
{
    cr_assert(my_getnbr("abc-42", 0) == -42);
}

Test(my_getnbr, stops_at_non_digit)
{
    cr_assert(my_getnbr("42abc", 0) == 42);
}

Test(my_getnbr, leading_zeros)
{
    cr_assert(my_getnbr("00042", 0) == 42);
}

Test(my_getnbr, start_in_middle)
{
    cr_assert(my_getnbr("hello123world", 5) == 123);
}

Test(my_getnbr, only_minus_sign)
{
    cr_assert(my_getnbr("-", 0) == 0);
}

Test(my_getnbr, only_letters_no_digits)
{
    cr_assert(my_getnbr("hello world", 0) == 0);
}

Test(my_getnbr, multiple_numbers_takes_first)
{
    cr_assert(my_getnbr("12 34", 0) == 12);
}