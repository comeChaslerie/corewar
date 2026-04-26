/*
** EPITECH PROJECT, 2025
** my_getnbr.c
** File description:
** return number
*/
#include <stdbool.h>
#include "utils.h"

bool is_nbr(char *str)
{
    for (unsigned int index = 0; index < my_strlen(str); index++) {
        if (str[index] < '0' || str[index] > '9')
            return false;
    }
    return true;
}
