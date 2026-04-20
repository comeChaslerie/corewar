/*
** EPITECH PROJECT, 2025
** my_put_dbl.c
** File description:
** print number
*/
#include "my.h"

int get_pow(double nbr, int times)
{
    int pow_nbr = nbr;

    for (int i = 0; i < (times - 1); i++)
        pow_nbr *= nbr;
    return pow_nbr;
}

void display_dbl(double dbl, int after_coma)
{
    if ((int)dbl == 0)
        my_putchar('0');
    else
        my_put_nbr((int)dbl);
    if (after_coma != 0)
        my_putchar('.');
    dbl -= (int)dbl;
    dbl *= 10;
    after_coma--;
    while ((int)dbl == 0 && after_coma >= 0) {
        my_putchar('0');
        dbl *= 10;
        after_coma--;
    }
    while (after_coma >= 0) {
        my_put_nbr((int)dbl);
        dbl -= (int)dbl;
        dbl *= 10;
        after_coma--;
    }
}

void my_put_dbl(double dbl, int after_coma)
{
    if (dbl < 0) {
        dbl *= -1.0;
        my_putchar('-');
    }
    dbl += 0.5 * get_pow(-0.01, after_coma);
    if (dbl == 0) {
        my_putchar('0');
        if (after_coma != 0)
            my_putchar('.');
        while (after_coma != 0) {
            my_putchar('0');
            after_coma--;
        }
    } else {
        display_dbl(dbl, after_coma);
    }
}
