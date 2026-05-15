/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** uctohex tests
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "compute.h"
#include "define.h"

Test(uctohex, basic)
{
    unsigned char reg[REG_SIZE] = {0xAB, 0xCD, 0xEF, 0x12};
    unsigned char *hex = uctohex(reg, REG_SIZE);

    cr_assert_not_null(hex);
    cr_assert_eq(hex[0], 0xA);
    cr_assert_eq(hex[1], 0xB);
    cr_assert_eq(hex[2], 0xC);
    cr_assert_eq(hex[3], 0xD);
    cr_assert_eq(hex[4], 0xE);
    cr_assert_eq(hex[5], 0xF);
    cr_assert_eq(hex[6], 0x1);
    cr_assert_eq(hex[7], 0x2);
    free(hex);
}

Test(uctohex, all_zero)
{
    unsigned char reg[REG_SIZE] = {0, 0, 0, 0};
    unsigned char *hex = uctohex(reg, REG_SIZE);

    cr_assert_not_null(hex);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(hex[i], 0);
    free(hex);
}

Test(uctohex, all_max)
{
    unsigned char reg[REG_SIZE] = {0xFF, 0xFF, 0xFF, 0xFF};
    unsigned char *hex = uctohex(reg, REG_SIZE);

    cr_assert_not_null(hex);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(hex[i], 0xF);
    free(hex);
}

Test(uctohex, smaller_size)
{
    unsigned char reg[2] = {0xAB, 0xCD};
    unsigned char *hex = uctohex(reg, 2);

    cr_assert_not_null(hex);
    cr_assert_eq(hex[0], 0xA);
    cr_assert_eq(hex[1], 0xB);
    cr_assert_eq(hex[2], 0xC);
    cr_assert_eq(hex[3], 0xD);
    cr_assert_eq(hex[4], 0);
    cr_assert_eq(hex[5], 0);
    cr_assert_eq(hex[6], 0);
    cr_assert_eq(hex[7], 0);
    free(hex);
}

Test(uctohex, single_byte)
{
    unsigned char reg[1] = {0x80};
    unsigned char *hex = uctohex(reg, 1);

    cr_assert_not_null(hex);
    cr_assert_eq(hex[0], 0x8);
    cr_assert_eq(hex[1], 0x0);
    for (int i = 2; i < HEXA_SIZE; i++)
        cr_assert_eq(hex[i], 0);
    free(hex);
}

Test(uctohex, size_zero)
{
    unsigned char reg[1] = {0xFF};
    unsigned char *hex = uctohex(reg, 0);

    cr_assert_not_null(hex);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(hex[i], 0);
    free(hex);
}

Test(uctohex, size_larger_than_reg)
{
    unsigned char reg[REG_SIZE] = {0x12, 0x34, 0x56, 0x78};
    unsigned char *hex = uctohex(reg, 100);

    cr_assert_not_null(hex);
    cr_assert_eq(hex[0], 0x1);
    cr_assert_eq(hex[7], 0x8);
    free(hex);
}
