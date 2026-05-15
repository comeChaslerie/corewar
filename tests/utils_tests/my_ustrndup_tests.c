/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_ustrndup tests
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "utils.h"

Test(my_ustrndup, basic)
{
    unsigned char src[] = {1, 2, 3, 4, 5};
    unsigned char *result = my_ustrndup(src, 0, 5);

    cr_assert_not_null(result);
    for (int i = 0; i < 5; i++)
        cr_assert_eq(result[i], i + 1);
    free(result);
}

Test(my_ustrndup, with_offset)
{
    unsigned char src[] = {0xA, 0xB, 0xC, 0xD};
    unsigned char *result = my_ustrndup(src, 1, 3);

    cr_assert_not_null(result);
    cr_assert_eq(result[0], 0xB);
    cr_assert_eq(result[1], 0xC);
    free(result);
}

Test(my_ustrndup, null_returns_null)
{
    cr_assert_null(my_ustrndup(NULL, 0, 5));
}

Test(my_ustrndup, equal_start_end)
{
    unsigned char src[] = {1, 2, 3};
    cr_assert_null(my_ustrndup(src, 1, 1));
}

Test(my_ustrndup, single_byte)
{
    unsigned char src[] = {0xFF};
    unsigned char *result = my_ustrndup(src, 0, 1);

    cr_assert_not_null(result);
    cr_assert_eq(result[0], 0xFF);
    free(result);
}

Test(my_ustrndup, with_zero_bytes)
{
    unsigned char src[] = {0, 0, 0, 0};
    unsigned char *result = my_ustrndup(src, 0, 4);

    cr_assert_not_null(result);
    for (int i = 0; i < 4; i++)
        cr_assert_eq(result[i], 0);
    free(result);
}
