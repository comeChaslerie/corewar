/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** give length
*/

#include <stdlib.h>

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
