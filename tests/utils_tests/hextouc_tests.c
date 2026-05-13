/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "hexa_calc.h"
#include "define.h"

Test(hextouc, basic_nbr)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    cr_assert(hex);
    hex[0] = 15;
    hex[1] = 12;
    hex[2] = 7;
    hex[3] = 3;
    hex[4] = 12;
    hex[5] = 14;
    hex[6] = 3;
    hex[7] = 8;
    cr_assert(hextouc(hex, reg));
    free(hex);
    free(reg);
}

Test(hextouc, basic_nbr_values_check)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    hex[0] = 15;
    hex[1] = 12;
    hex[2] = 7;
    hex[3] = 3;
    hex[4] = 12;
    hex[5] = 14;
    hex[6] = 3;
    hex[7] = 8;
    hextouc(hex, reg);
    cr_assert_eq(reg[0], 0xFC);
    cr_assert_eq(reg[1], 0x73);
    cr_assert_eq(reg[2], 0xCE);
    cr_assert_eq(reg[3], 0x38);
    free(hex);
    free(reg);
}

Test(hextouc, all_zero)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    for (int i = 0; i < HEXA_SIZE; i++)
        hex[i] = 0;
    cr_assert(hextouc(hex, reg));
    for (int i = 0; i < REG_SIZE; i++)
        cr_assert_eq(reg[i], 0);
    free(hex);
    free(reg);
}

Test(hextouc, all_max_nibble)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    for (int i = 0; i < HEXA_SIZE; i++)
        hex[i] = HEXA_MAX;
    cr_assert(hextouc(hex, reg));
    for (int i = 0; i < REG_SIZE; i++)
        cr_assert_eq(reg[i], 0xFF);
    free(hex);
    free(reg);
}

Test(hextouc, only_high_nibbles)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    hex[0] = 1;
    hex[1] = 0;
    hex[2] = 2;
    hex[3] = 0;
    hex[4] = 3;
    hex[5] = 0;
    hex[6] = 4;
    hex[7] = 0;
    hextouc(hex, reg);
    cr_assert_eq(reg[0], 0x10);
    cr_assert_eq(reg[1], 0x20);
    cr_assert_eq(reg[2], 0x30);
    cr_assert_eq(reg[3], 0x40);
    free(hex);
    free(reg);
}

Test(hextouc, only_low_nibbles)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    hex[0] = 0;
    hex[1] = 1;
    hex[2] = 0;
    hex[3] = 2;
    hex[4] = 0;
    hex[5] = 3;
    hex[6] = 0;
    hex[7] = 4;
    hextouc(hex, reg);
    cr_assert_eq(reg[0], 0x01);
    cr_assert_eq(reg[1], 0x02);
    cr_assert_eq(reg[2], 0x03);
    cr_assert_eq(reg[3], 0x04);
    free(hex);
    free(reg);
}

Test(hextouc, alternating_high_low)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    hex[0] = 0xA;
    hex[1] = 0x5;
    hex[2] = 0xA;
    hex[3] = 0x5;
    hex[4] = 0xA;
    hex[5] = 0x5;
    hex[6] = 0xA;
    hex[7] = 0x5;
    hextouc(hex, reg);
    for (int i = 0; i < REG_SIZE; i++)
        cr_assert_eq(reg[i], 0xA5);
    free(hex);
    free(reg);
}

Test(hextouc, alternating_low_high)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    hex[0] = 0x5;
    hex[1] = 0xA;
    hex[2] = 0x5;
    hex[3] = 0xA;
    hex[4] = 0x5;
    hex[5] = 0xA;
    hex[6] = 0x5;
    hex[7] = 0xA;
    hextouc(hex, reg);
    for (int i = 0; i < REG_SIZE; i++)
        cr_assert_eq(reg[i], 0x5A);
    free(hex);
    free(reg);
}

Test(hextouc, sequential_nibbles)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    for (int i = 0; i < HEXA_SIZE; i++)
        hex[i] = i;
    hextouc(hex, reg);
    cr_assert_eq(reg[0], 0x01);
    cr_assert_eq(reg[1], 0x23);
    cr_assert_eq(reg[2], 0x45);
    cr_assert_eq(reg[3], 0x67);
    free(hex);
    free(reg);
}

Test(hextouc, only_first_byte_set)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    for (int i = 0; i < HEXA_SIZE; i++)
        hex[i] = 0;
    hex[0] = 0xF;
    hex[1] = 0xF;
    hextouc(hex, reg);
    cr_assert_eq(reg[0], 0xFF);
    cr_assert_eq(reg[1], 0x00);
    cr_assert_eq(reg[2], 0x00);
    cr_assert_eq(reg[3], 0x00);
    free(hex);
    free(reg);
}

Test(hextouc, only_last_byte_set)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    for (int i = 0; i < HEXA_SIZE; i++)
        hex[i] = 0;
    hex[6] = 0xF;
    hex[7] = 0xF;
    hextouc(hex, reg);
    cr_assert_eq(reg[0], 0x00);
    cr_assert_eq(reg[1], 0x00);
    cr_assert_eq(reg[2], 0x00);
    cr_assert_eq(reg[3], 0xFF);
    free(hex);
    free(reg);
}

Test(hextouc, return_value_is_true)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    for (int i = 0; i < HEXA_SIZE; i++)
        hex[i] = 0;
    cr_assert_eq(hextouc(hex, reg), true);
    free(hex);
    free(reg);
}

Test(hextouc, reg_overwritten)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    for (int i = 0; i < REG_SIZE; i++)
        reg[i] = 0xAB;
    for (int i = 0; i < HEXA_SIZE; i++)
        hex[i] = 0;
    hextouc(hex, reg);
    for (int i = 0; i < REG_SIZE; i++)
        cr_assert_eq(reg[i], 0x00);
    free(hex);
    free(reg);
}

Test(hextouc, single_bit_low)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    for (int i = 0; i < HEXA_SIZE; i++)
        hex[i] = 0;
    hex[7] = 1;
    hextouc(hex, reg);
    cr_assert_eq(reg[0], 0x00);
    cr_assert_eq(reg[1], 0x00);
    cr_assert_eq(reg[2], 0x00);
    cr_assert_eq(reg[3], 0x01);
    free(hex);
    free(reg);
}

Test(hextouc, byte_value_128)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned char *reg = malloc(sizeof(unsigned char) * REG_SIZE);

    for (int i = 0; i < HEXA_SIZE; i++)
        hex[i] = 0;
    hex[0] = 8;
    hextouc(hex, reg);
    cr_assert_eq(reg[0], 0x80);
    free(hex);
    free(reg);
}
