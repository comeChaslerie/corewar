/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** put_str tests
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"

Test(put_str, basic, .init = cr_redirect_stdout)
{
    put_str("hello");
    fflush(stdout);
    cr_assert_stdout_eq_str("hello");
}

Test(put_str, empty, .init = cr_redirect_stdout)
{
    put_str("");
    fflush(stdout);
    cr_assert_stdout_eq_str("");
}

Test(put_str, with_special_chars, .init = cr_redirect_stdout)
{
    put_str("a\tb\nc");
    fflush(stdout);
    cr_assert_stdout_eq_str("a\tb\nc");
}

Test(put_str, single_char, .init = cr_redirect_stdout)
{
    put_str("X");
    fflush(stdout);
    cr_assert_stdout_eq_str("X");
}

Test(put_str, long_string, .init = cr_redirect_stdout)
{
    put_str("The quick brown fox jumps over the lazy dog");
    fflush(stdout);
    cr_assert_stdout_eq_str("The quick brown fox jumps over the lazy dog");
}

Test(put_str, null_does_not_crash)
{
    put_str(NULL);
    cr_assert(1);
}

Test(my_putchar, basic, .init = cr_redirect_stdout)
{
    my_putchar('A');
    fflush(stdout);
    cr_assert_stdout_eq_str("A");
}

Test(my_putchar, newline, .init = cr_redirect_stdout)
{
    my_putchar('\n');
    fflush(stdout);
    cr_assert_stdout_eq_str("\n");
}
