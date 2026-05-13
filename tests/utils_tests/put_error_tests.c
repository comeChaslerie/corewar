/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** put_error tests
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "utils.h"


Test(put_error, false_return)
{
    cr_assert(put_error("error", false) == false);
}

Test(put_error, null_return)
{
    cr_assert(put_error("error", NULL) == NULL);
}

Test(put_error, true_return)
{
    cr_assert(put_error("error", (void *)true) == (void *)true);
}

Test(put_error, pointer_return)
{
    int value = 42;

    cr_assert(put_error("error", &value) == &value);
}

Test(put_error, returns_same_pointer)
{
    char *ptr = "some string";

    cr_assert(put_error("error", ptr) == ptr);
}

Test(put_error, empty_message)
{
    cr_assert(put_error("", NULL) == NULL);
}

Test(put_error, long_message)
{
    cr_assert(put_error("This is a much longer error message with details",
        NULL) == NULL);
}

Test(put_error, special_chars_message)
{
    cr_assert(put_error("error!\t<>?", NULL) == NULL);
}

Test(put_error, writes_to_stderr, .init = cr_redirect_stderr)
{
    put_error("hello", NULL);
    cr_assert_stderr_eq_str("hello\n");
}

Test(put_error, writes_empty_message_with_newline, .init = cr_redirect_stderr)
{
    put_error("", NULL);
    cr_assert_stderr_eq_str("\n");
}

Test(put_error, writes_exact_message, .init = cr_redirect_stderr)
{
    put_error("specific error", NULL);
    cr_assert_stderr_eq_str("specific error\n");
}
