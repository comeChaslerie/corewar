/*
** EPITECH PROJECT, 2025
** my_put_nbr.c
** File description:
** print number
*/
#include "my.h"

char get_sign_nb(int n)
{
    if (n < 0)
        return ('-');
    else
        return (0);
}

int recursive(int n)
{
    int rest = 0;
    int rest_str = 0;

    if (n != 0) {
        rest = n % 10;
        n = n / 10;
        recursive(n);
        rest_str = rest + '0';
        my_putchar(rest_str);
    }
    return 0;
}

void my_print_except(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int n)
{
    int sign = 0;

    if (n == (-2147483648)) {
        my_print_except();
    } else {
        sign = get_sign_nb(n);
        if (sign == '-') {
            n = n * (-1);
            my_putchar(sign);
        }
        if (n == 0)
            my_putchar('0');
        else
            recursive(n);
    }
    return 0;
}
