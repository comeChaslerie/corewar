/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** free_values tests
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "utils.h"

Test(free_values, basic)
{
    void *vals[3] = {malloc(10), malloc(20), malloc(30)};
    free_values(vals, 3);
    cr_assert_null(vals[0]);
    cr_assert_null(vals[1]);
    cr_assert_null(vals[2]);
}

Test(free_values, with_nulls)
{
    void *vals[3] = {NULL, malloc(10), NULL};
    free_values(vals, 3);
    cr_assert_null(vals[1]);
}

Test(free_values, all_null)
{
    void *vals[3] = {NULL, NULL, NULL};
    free_values(vals, 3);
    cr_assert_null(vals[0]);
}

Test(free_values, zero_count)
{
    void *vals[1] = {NULL};
    free_values(vals, 0);
    cr_assert(1);
}

Test(free_values, single)
{
    void *vals[1] = {malloc(1)};
    free_values(vals, 1);
    cr_assert_null(vals[0]);
}
