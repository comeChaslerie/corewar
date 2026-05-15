/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** hexa_sum tests
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "compute.h"

static unsigned char *make_hex(unsigned char fill)
{
    unsigned char *h = malloc(HEXA_SIZE);
    for (int i = 0; i < HEXA_SIZE; i++)
        h[i] = fill;
    return h;
}

Test(hexa_sum, basic)
{
    unsigned char *a = make_hex(0);
    unsigned char *b = make_hex(0);
    unsigned char *r = make_hex(0);
    a[7] = 1;
    b[7] = 2;

    cr_assert(hexa_sum(&a, &b, &r));
    cr_assert_eq(r[7], 3);
    free(a); free(b); free(r);
}

Test(hexa_sum, with_carry)
{
    unsigned char *a = make_hex(0);
    unsigned char *b = make_hex(0);
    unsigned char *r = make_hex(0);
    a[7] = 0xF;
    b[7] = 0x1;

    hexa_sum(&a, &b, &r);
    cr_assert_eq(r[7], 0);
    cr_assert_eq(r[6], 1);
    free(a); free(b); free(r);
}

Test(hexa_sum, all_max)
{
    unsigned char *a = make_hex(0xF);
    unsigned char *b = make_hex(0);
    unsigned char *r = make_hex(0);
    b[7] = 1;

    hexa_sum(&a, &b, &r);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0);
    free(a); free(b); free(r);
}

Test(hexa_sum, both_zero)
{
    unsigned char *a = make_hex(0);
    unsigned char *b = make_hex(0);
    unsigned char *r = make_hex(0);

    hexa_sum(&a, &b, &r);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0);
    free(a); free(b); free(r);
}

Test(hexa_sum, returns_true)
{
    unsigned char *a = make_hex(1);
    unsigned char *b = make_hex(1);
    unsigned char *r = make_hex(0);

    cr_assert_eq(hexa_sum(&a, &b, &r), true);
    free(a); free(b); free(r);
}

Test(hexa_diff, basic)
{
    unsigned char *a = make_hex(0);
    unsigned char *b = make_hex(0);
    unsigned char *r = make_hex(0);
    a[7] = 5;
    b[7] = 2;

    hexa_diff(&a, &b, &r);
    cr_assert_eq(r[7], 3);
    free(a); free(b); free(r);
}

Test(hexa_diff, with_borrow)
{
    unsigned char *a = make_hex(0);
    unsigned char *b = make_hex(0);
    unsigned char *r = make_hex(0);
    a[6] = 1;
    b[7] = 1;

    hexa_diff(&a, &b, &r);
    cr_assert_eq(r[7], 0xF);
    cr_assert_eq(r[6], 0);
    free(a); free(b); free(r);
}

Test(hexa_diff, equal_values)
{
    unsigned char *a = make_hex(5);
    unsigned char *b = make_hex(5);
    unsigned char *r = make_hex(0);

    hexa_diff(&a, &b, &r);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0);
    free(a); free(b); free(r);
}

Test(hexa_diff, zero_minus_zero)
{
    unsigned char *a = make_hex(0);
    unsigned char *b = make_hex(0);
    unsigned char *r = make_hex(0);

    hexa_diff(&a, &b, &r);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0);
    free(a); free(b); free(r);
}

Test(bin_and, basic)
{
    unsigned char *a = make_hex(0xF);
    unsigned char *b = make_hex(0xA);
    unsigned char *r = make_hex(0);

    cr_assert(bin_and(&a, &b, &r));
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0xA);
    free(a); free(b); free(r);
}

Test(bin_and, all_zero)
{
    unsigned char *a = make_hex(0);
    unsigned char *b = make_hex(0xF);
    unsigned char *r = make_hex(0);

    bin_and(&a, &b, &r);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0);
    free(a); free(b); free(r);
}

Test(bin_or, basic)
{
    unsigned char *a = make_hex(0x0);
    unsigned char *b = make_hex(0xA);
    unsigned char *r = make_hex(0);

    cr_assert(bin_or(&a, &b, &r));
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0xA);
    free(a); free(b); free(r);
}

Test(bin_or, all_set)
{
    unsigned char *a = make_hex(0xF);
    unsigned char *b = make_hex(0);
    unsigned char *r = make_hex(0);

    bin_or(&a, &b, &r);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0xF);
    free(a); free(b); free(r);
}

Test(bin_xor, basic)
{
    unsigned char *a = make_hex(0xF);
    unsigned char *b = make_hex(0xA);
    unsigned char *r = make_hex(0);

    cr_assert(bin_xor(&a, &b, &r));
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0x5);
    free(a); free(b); free(r);
}

Test(bin_xor, identical_zeros_out)
{
    unsigned char *a = make_hex(0xA);
    unsigned char *b = make_hex(0xA);
    unsigned char *r = make_hex(0);

    bin_xor(&a, &b, &r);
    for (int i = 0; i < HEXA_SIZE; i++)
        cr_assert_eq(r[i], 0);
    free(a); free(b); free(r);
}
