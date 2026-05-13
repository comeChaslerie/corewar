/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_strdup tests
*/
#include <criterion/criterion.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"


Test(my_strdup, basic_dup)
{
    char *my_dup = my_strdup("dup");

    cr_assert(strcmp(my_dup, "dup") == 0);
    free(my_dup);
}

Test(my_strdup, empty_dup)
{
    char *my_dup = my_strdup("");

    cr_assert(strcmp(my_dup, "") == 0);
    free(my_dup);
}

Test(my_strdup, null_dup)
{
    char *my_dup = my_strdup(NULL);

    cr_assert(my_dup == NULL);
    free(my_dup);
}


Test(my_strndup, basic_full_dup)
{
    char *my_dup = my_strndup("dup", 0, 3);

    cr_assert(strcmp(my_dup, "dup") == 0);
    free(my_dup);
}

Test(my_strndup, out_of_range_dup)
{
    char *my_dup = my_strndup("", 0, 2);

    cr_assert(strcmp(my_dup, "") == 0);
    free(my_dup);
}

Test(my_strndup, other_start_dup)
{
    char *my_dup = my_strndup("dup", 1, 3);

    cr_assert(strcmp(my_dup, "up") == 0);
    free(my_dup);
}

Test(my_strndup, null_dup)
{
    char *my_dup = my_strndup("NULL", 4, 0);

    cr_assert(my_dup == NULL);
    free(my_dup);
}

Test(my_strdup, long_string)
{
    char *my_dup = my_strdup("The quick brown fox jumps over the lazy dog");

    cr_assert_not_null(my_dup);
    cr_assert(strcmp(my_dup, "The quick brown fox jumps over the lazy dog") == 0);
    free(my_dup);
}

Test(my_strdup, single_char)
{
    char *my_dup = my_strdup("a");

    cr_assert_not_null(my_dup);
    cr_assert(strcmp(my_dup, "a") == 0);
    free(my_dup);
}

Test(my_strdup, with_special_chars)
{
    char *my_dup = my_strdup("hello\tworld\n!");

    cr_assert_not_null(my_dup);
    cr_assert(strcmp(my_dup, "hello\tworld\n!") == 0);
    free(my_dup);
}

Test(my_strdup, with_digits)
{
    char *my_dup = my_strdup("1234567890");

    cr_assert_not_null(my_dup);
    cr_assert(strcmp(my_dup, "1234567890") == 0);
    free(my_dup);
}

Test(my_strdup, independent_memory)
{
    char src[] = "original";
    char *my_dup = my_strdup(src);

    cr_assert_not_null(my_dup);
    src[0] = 'X';
    cr_assert(strcmp(my_dup, "original") == 0);
    free(my_dup);
}

Test(my_strdup, null_terminated)
{
    char *my_dup = my_strdup("abc");

    cr_assert_not_null(my_dup);
    cr_assert_eq(my_dup[3], '\0');
    free(my_dup);
}

Test(my_strndup, single_char_range)
{
    char *my_dup = my_strndup("abcdef", 2, 3);

    cr_assert_not_null(my_dup);
    cr_assert(strcmp(my_dup, "c") == 0);
    free(my_dup);
}

Test(my_strndup, empty_range)
{
    char *my_dup = my_strndup("abc", 1, 1);

    cr_assert_not_null(my_dup);
    cr_assert(strcmp(my_dup, "") == 0);
    free(my_dup);
}

Test(my_strndup, full_string)
{
    char *my_dup = my_strndup("hello", 0, 5);

    cr_assert_not_null(my_dup);
    cr_assert(strcmp(my_dup, "hello") == 0);
    free(my_dup);
}

Test(my_strndup, middle_range)
{
    char *my_dup = my_strndup("abcdefgh", 2, 6);

    cr_assert_not_null(my_dup);
    cr_assert(strcmp(my_dup, "cdef") == 0);
    free(my_dup);
}

Test(my_strndup, null_src)
{
    char *my_dup = my_strndup(NULL, 0, 5);

    cr_assert(my_dup == NULL);
}

Test(my_strndup, negative_length)
{
    char *my_dup = my_strndup("hello", 3, 1);

    cr_assert(my_dup == NULL);
}

Test(my_strndup, null_terminated)
{
    char *my_dup = my_strndup("hello", 0, 3);

    cr_assert_not_null(my_dup);
    cr_assert_eq(my_dup[3], '\0');
    free(my_dup);
}

Test(my_strndup, length_matches_range)
{
    char *my_dup = my_strndup("hello world", 6, 11);

    cr_assert_not_null(my_dup);
    cr_assert_eq(strlen(my_dup), 5);
    cr_assert(strcmp(my_dup, "world") == 0);
    free(my_dup);
}
