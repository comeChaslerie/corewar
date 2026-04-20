/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** reverse a string
*/
#include <stdlib.h>
#include "my.h"

char *my_revstr(char *str)
{
    int len = 0;
    char *new_str;

    if (str == NULL)
        return NULL;
    len = my_strlen(str);
    new_str = malloc(sizeof(char) * (len + 1));
    if (new_str == NULL)
        return NULL;
    new_str[len] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
        new_str[len - 1 - i] = str[i];
    return (new_str);
}
