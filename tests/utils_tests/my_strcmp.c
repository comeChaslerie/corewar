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