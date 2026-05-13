/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_strcmp tests
*/
#include <criterion/criterion.h>
#include "utils.h"


Test(my_strcmp, basic_true_comparison)
{
    cr_assert(my_strcmp("aa", "aa") == 0);
}

Test(my_strcmp, basic_false_comparison)
{
    cr_assert(my_strcmp("aa", "bb") != 0);
}

Test(my_strcmp, mixted_true_comparison)
{
    cr_assert(my_strcmp("-ab12!", "-ab12!") == 0);
}

Test(my_strcmp, first_null_comparison)
{
    cr_assert(my_strcmp(NULL, "-ab12!") == 0);
}

Test(my_strcmp, second_null_comparison)
{
    cr_assert(my_strcmp("ab12", NULL) == 0);
}




Test(my_strncmp, basic_true_comparison)
{
    cr_assert(my_strncmp("aaaa", "aabb", 2) == 0);
}

Test(my_strncmp, basic_false_comparison)
{
    cr_assert(my_strncmp("aaaa", "bbbb", 2) != 0);
}

Test(my_strncmp, mixted_true_comparison)
{
    cr_assert(my_strncmp("-ab12!", "-ab122", 3) == 0);
}

Test(my_strncmp, edge_case_start_comparison)
{
    cr_assert(my_strncmp("aaaa", "bbbb", 0) == 0);
}

Test(my_strncmp, edge_case_end_comparison)
{
    cr_assert(my_strncmp("-ab12!", "-ab12!", 6) == 0);
}

Test(my_strncmp, first_null_comparison)
{
    cr_assert(my_strncmp(NULL, "-ab12!", 2) == 0);
}

Test(my_strncmp, second_null_comparison)
{
    cr_assert(my_strncmp("ab12", NULL, 2) == 0);
}

Test(my_strcmp, both_empty)
{
    cr_assert(my_strcmp("", "") == 0);
}

Test(my_strcmp, first_empty)
{
    cr_assert(my_strcmp("", "abc") != 0);
}

Test(my_strcmp, second_empty)
{
    cr_assert(my_strcmp("abc", "") != 0);
}

Test(my_strcmp, different_length_prefix)
{
    cr_assert(my_strcmp("abc", "abcdef") != 0);
}

Test(my_strcmp, longer_first)
{
    cr_assert(my_strcmp("abcdef", "abc") != 0);
}

Test(my_strcmp, single_char_equal)
{
    cr_assert(my_strcmp("a", "a") == 0);
}

Test(my_strcmp, single_char_different)
{
    cr_assert(my_strcmp("a", "b") < 0);
}

Test(my_strcmp, lower_vs_upper)
{
    cr_assert(my_strcmp("a", "A") > 0);
}

Test(my_strcmp, return_negative_difference)
{
    cr_assert(my_strcmp("aaa", "aab") < 0);
}

Test(my_strcmp, return_positive_difference)
{
    cr_assert(my_strcmp("aab", "aaa") > 0);
}

Test(my_strcmp, both_null)
{
    cr_assert(my_strcmp(NULL, NULL) == 0);
}

Test(my_strcmp, with_special_chars)
{
    cr_assert(my_strcmp("hello!", "hello?") < 0);
}

Test(my_strcmp, differ_at_first_char)
{
    cr_assert(my_strcmp("abc", "xbc") < 0);
}

Test(my_strncmp, both_empty)
{
    cr_assert(my_strncmp("", "", 5) == 0);
}

Test(my_strncmp, n_larger_than_strings)
{
    cr_assert(my_strncmp("ab", "ab", 100) == 0);
}

Test(my_strncmp, n_one)
{
    cr_assert(my_strncmp("apple", "abc", 1) == 0);
}

Test(my_strncmp, both_null_n_positive)
{
    cr_assert(my_strncmp(NULL, NULL, 5) == 0);
}

Test(my_strncmp, equal_at_n_minus_1)
{
    cr_assert(my_strncmp("abXdef", "abYdef", 2) == 0);
}

Test(my_strncmp, differ_at_n_minus_1)
{
    cr_assert(my_strncmp("abXdef", "abYdef", 3) != 0);
}

Test(my_strncmp, full_compare_equal)
{
    cr_assert(my_strncmp("hello", "hello", 5) == 0);
}

Test(my_strncmp, single_char_n_one_different)
{
    cr_assert(my_strncmp("a", "b", 1) != 0);
}

Test(my_strncmp, single_char_n_one_equal)
{
    cr_assert(my_strncmp("a", "a", 1) == 0);
}