/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_strlen tests
*/
#include <criterion/criterion.h>
#include "utils.h"

Test(my_strlen, basic)
{
    cr_assert_eq(my_strlen("hello"), 5);
}

Test(my_strlen, empty)
{
    cr_assert_eq(my_strlen(""), 0);
}

Test(my_strlen, null_returns_zero)
{
    cr_assert_eq(my_strlen(NULL), 0);
}

Test(my_strlen, single_char)
{
    cr_assert_eq(my_strlen("a"), 1);
}

Test(my_strlen, with_spaces)
{
    cr_assert_eq(my_strlen("a b c"), 5);
}

Test(my_strlen, special_chars)
{
    cr_assert_eq(my_strlen("\t\n\r"), 3);
}

Test(my_strlen, long_string)
{
    cr_assert_eq(my_strlen("The quick brown fox jumps over the lazy dog"), 43);
}
