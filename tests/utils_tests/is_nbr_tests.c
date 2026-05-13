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

Test(is_nbr, empty_string)
{
    cr_assert(is_nbr("") == true);
}

Test(is_nbr, single_digit_zero)
{
    cr_assert(is_nbr("0") == true);
}

Test(is_nbr, single_digit_nine)
{
    cr_assert(is_nbr("9") == true);
}

Test(is_nbr, long_number)
{
    cr_assert(is_nbr("1234567890") == true);
}

Test(is_nbr, leading_zero)
{
    cr_assert(is_nbr("0012") == true);
}

Test(is_nbr, only_zeros)
{
    cr_assert(is_nbr("00000") == true);
}

Test(is_nbr, plus_sign)
{
    cr_assert(is_nbr("+12") == false);
}

Test(is_nbr, with_space)
{
    cr_assert(is_nbr("12 34") == false);
}

Test(is_nbr, leading_space)
{
    cr_assert(is_nbr(" 12") == false);
}

Test(is_nbr, trailing_space)
{
    cr_assert(is_nbr("12 ") == false);
}

Test(is_nbr, with_dot)
{
    cr_assert(is_nbr("12.34") == false);
}

Test(is_nbr, with_comma)
{
    cr_assert(is_nbr("12,34") == false);
}

Test(is_nbr, hexadecimal)
{
    cr_assert(is_nbr("0x1F") == false);
}

Test(is_nbr, only_uppercase)
{
    cr_assert(is_nbr("AB") == false);
}

Test(is_nbr, digit_then_letter)
{
    cr_assert(is_nbr("12a") == false);
}

Test(is_nbr, letter_then_digit)
{
    cr_assert(is_nbr("a12") == false);
}

Test(is_nbr, special_char_only)
{
    cr_assert(is_nbr("@!#") == false);
}

Test(is_nbr, char_just_below_zero)
{
    cr_assert(is_nbr("/") == false);
}

Test(is_nbr, char_just_above_nine)
{
    cr_assert(is_nbr(":") == false);
}

Test(is_nbr, tab_only)
{
    cr_assert(is_nbr("\t") == false);
}
