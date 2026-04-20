/*
** EPITECH PROJECT, 2025
** put_error.c
** File description:
** display in error canal
*/
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void put_error(char *str)
{
    if (str == NULL)
        return;
    write(2, str, my_strlen(str));
}
