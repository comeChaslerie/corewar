/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** uctoui tests
*/
#include <criterion/criterion.h>
#include "compute.h"
#include "define.h"

Test(uctoui, basic)
{
    unsigned char val[REG_SIZE] = {0, 0, 0, 0x2A};

    cr_assert_eq(uctoui(val, REG_SIZE), 42);
}

Test(uctoui, all_zero)
{
    unsigned char val[REG_SIZE] = {0, 0, 0, 0};

    cr_assert_eq(uctoui(val, REG_SIZE), 0);
}

Test(uctoui, single_byte_max)
{
    unsigned char val[1] = {0xFF};

    cr_assert_eq(uctoui(val, 1), 255);
}

Test(uctoui, two_bytes)
{
    unsigned char val[2] = {0x01, 0x00};

    cr_assert_eq(uctoui(val, 2), 256);
}

Test(uctoui, max_4_bytes)
{
    unsigned char val[REG_SIZE] = {0xFF, 0xFF, 0xFF, 0xFF};

    cr_assert_eq(uctoui(val, REG_SIZE), 4294967295u);
}

Test(uctoui, size_zero)
{
    unsigned char val[1] = {0xFF};

    cr_assert_eq(uctoui(val, 0), 0);
}

Test(uctoui, mixed)
{
    unsigned char val[REG_SIZE] = {0x00, 0x00, 0x01, 0x00};

    cr_assert_eq(uctoui(val, REG_SIZE), 256);
}

Test(uctoui, ind_size)
{
    unsigned char val[2] = {0x01, 0x02};

    cr_assert_eq(uctoui(val, 2), 0x0102);
}
