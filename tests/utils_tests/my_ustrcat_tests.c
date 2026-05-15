/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_ustrcat tests
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "utils.h"

Test(my_ustrcat, basic)
{
    unsigned int size = 0;
    unsigned char *result = my_ustrcat(NULL, &size,
        (unsigned char *)"abc", 3);

    cr_assert_not_null(result);
    cr_assert_eq(size, 3);
    cr_assert_eq(result[0], 'a');
    cr_assert_eq(result[1], 'b');
    cr_assert_eq(result[2], 'c');
    free(result);
}

Test(my_ustrcat, append)
{
    unsigned int size = 3;
    unsigned char *dest = malloc(3);
    dest[0] = 'a'; dest[1] = 'b'; dest[2] = 'c';
    unsigned char *result = my_ustrcat(dest, &size,
        (unsigned char *)"de", 2);

    cr_assert_not_null(result);
    cr_assert_eq(size, 5);
    cr_assert_eq(result[3], 'd');
    cr_assert_eq(result[4], 'e');
    free(result);
}

Test(my_ustrcat, null_dest_with_nonzero_size)
{
    unsigned int size = 5;
    unsigned char *result = my_ustrcat(NULL, &size,
        (unsigned char *)"xy", 2);

    cr_assert_null(result);
}

Test(my_ustrcat, null_src_with_nonzero_size)
{
    unsigned int size = 0;
    unsigned char *result = my_ustrcat(NULL, &size, NULL, 5);

    cr_assert_null(result);
}

Test(my_ustrcat, both_zero)
{
    unsigned int size = 0;
    unsigned char *result = my_ustrcat(NULL, &size, NULL, 0);

    cr_assert_eq(size, 0);
    free(result);
}

Test(my_ustrcat, append_zero_bytes)
{
    unsigned int size = 3;
    unsigned char *dest = malloc(3);
    dest[0] = 'x'; dest[1] = 'y'; dest[2] = 'z';
    unsigned char *result = my_ustrcat(dest, &size, NULL, 0);

    cr_assert_eq(size, 3);
    free(result);
}

Test(my_ustrcat, binary_data)
{
    unsigned int size = 0;
    unsigned char data[] = {0x00, 0xFF, 0x42, 0x00};
    unsigned char *result = my_ustrcat(NULL, &size, data, 4);

    cr_assert_not_null(result);
    cr_assert_eq(size, 4);
    cr_assert_eq(result[0], 0x00);
    cr_assert_eq(result[1], 0xFF);
    cr_assert_eq(result[2], 0x42);
    cr_assert_eq(result[3], 0x00);
    free(result);
}
