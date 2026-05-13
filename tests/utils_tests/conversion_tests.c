/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <string.h>
#include <criterion/criterion.h>
#include "utils.h"

Test(to_bin, basic_nbr)
{
    char *bin = to_bin((unsigned char)255);

    cr_assert(bin);
    cr_assert_str_eq(bin, "11111111");
    free(bin);
}

Test(to_bin, zero)
{
    char *bin = to_bin((unsigned char)0);

    cr_assert(bin);
    cr_assert_str_eq(bin, "00000000");
    free(bin);
}

Test(to_bin, one)
{
    char *bin = to_bin((unsigned char)1);

    cr_assert(bin);
    cr_assert_str_eq(bin, "00000001");
    free(bin);
}

Test(to_bin, two)
{
    char *bin = to_bin((unsigned char)2);

    cr_assert(bin);
    cr_assert_str_eq(bin, "00000010");
    free(bin);
}

Test(to_bin, msb_only)
{
    char *bin = to_bin((unsigned char)128);

    cr_assert(bin);
    cr_assert_str_eq(bin, "10000000");
    free(bin);
}

Test(to_bin, all_but_msb)
{
    char *bin = to_bin((unsigned char)127);

    cr_assert(bin);
    cr_assert_str_eq(bin, "01111111");
    free(bin);
}

Test(to_bin, alternating_high)
{
    char *bin = to_bin((unsigned char)170);

    cr_assert(bin);
    cr_assert_str_eq(bin, "10101010");
    free(bin);
}

Test(to_bin, alternating_low)
{
    char *bin = to_bin((unsigned char)85);

    cr_assert(bin);
    cr_assert_str_eq(bin, "01010101");
    free(bin);
}

Test(to_bin, power_of_two_16)
{
    char *bin = to_bin((unsigned char)16);

    cr_assert(bin);
    cr_assert_str_eq(bin, "00010000");
    free(bin);
}

Test(to_bin, power_of_two_64)
{
    char *bin = to_bin((unsigned char)64);

    cr_assert(bin);
    cr_assert_str_eq(bin, "01000000");
    free(bin);
}

Test(to_bin, all_but_lsb)
{
    char *bin = to_bin((unsigned char)254);

    cr_assert(bin);
    cr_assert_str_eq(bin, "11111110");
    free(bin);
}

Test(to_bin, low_nibble)
{
    char *bin = to_bin((unsigned char)15);

    cr_assert(bin);
    cr_assert_str_eq(bin, "00001111");
    free(bin);
}

Test(to_bin, high_nibble)
{
    char *bin = to_bin((unsigned char)240);

    cr_assert(bin);
    cr_assert_str_eq(bin, "11110000");
    free(bin);
}

Test(to_bin, length_is_eight)
{
    char *bin = to_bin((unsigned char)42);

    cr_assert(bin);
    cr_assert_eq(strlen(bin), 8);
    free(bin);
}

Test(to_bin, null_terminated)
{
    char *bin = to_bin((unsigned char)123);

    cr_assert(bin);
    cr_assert_eq(bin[8], '\0');
    free(bin);
}

Test(to_bin, overflow_wraps_to_zero)
{
    char *bin = to_bin((unsigned char)256);

    cr_assert(bin);
    cr_assert_str_eq(bin, "00000000");
    free(bin);
}

Test(to_bin, negative_wraps_to_max)
{
    char *bin = to_bin((unsigned char)-1);

    cr_assert(bin);
    cr_assert_str_eq(bin, "11111111");
    free(bin);
}

Test(to_bin, arbitrary_value)
{
    char *bin = to_bin((unsigned char)42);

    cr_assert(bin);
    cr_assert_str_eq(bin, "00101010");
    free(bin);
}
