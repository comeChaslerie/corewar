/*
** EPITECH PROJECT, 2025
** my_getnbr.c
** File description:
** return number
*/
#include <stdlib.h>

static int get_sign(char const *str, int i)
{
    int sign = 1;

    while (i >= 0) {
        if (str[i] == '-')
            sign *= -1;
        i--;
    }
    return (sign);
}

static int get_start(char const *str, int i)
{
    while (str[i] < '0' || str[i] > '9')
        if (str[i] == '\0')
            return (0);
        else
            i++;
    return i;
}

int my_getnbr(char const *str, int start)
{
    int i = start;
    int sign = 1;
    long int result = 0;

    if (str == NULL || start < 0)
        return 0;
    i = get_start(str, i);
    if (i > 0)
        if ((i - 1) >= start && (str[i - 1] == '-' || str[i - 1] == '+'))
            sign = get_sign(str, i);
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    result *= sign;
    if (result < -2147483648 || result > 2147483647)
        return (0);
    else
        return result;
}
