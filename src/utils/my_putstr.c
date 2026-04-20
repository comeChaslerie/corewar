/*
** EPITECH PROJECT, 2025
** my_putstr.c
** File description:
** print a string
*/
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void my_putstr(char *str)
{
    if (str == NULL)
        return;
    write(1, str, my_strlen(str));
}
