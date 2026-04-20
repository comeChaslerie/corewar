/*
** EPITECH PROJECT, 2025
** strlow_strup
** File description:
** return a string in either lowcase or uppercase
*/
#include <stdlib.h>
#include "my.h"

char *my_strlow(char *src)
{
    char *str = NULL;

    if (src == NULL)
        return NULL;
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return NULL;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] <= 'Z' && src[i] >= 'A')
            str[i] = src[i] + 32;
        else
            str[i] = src[i];
        str[i + 1] = '\0';
    }
    return (str);
}

char *my_strup(char *src)
{
    char *str = NULL;

    if (src == NULL)
        return NULL;
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return NULL;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] <= 'z' && src[i] >= 'a')
            str[i] = src[i] - 32;
        else
            str[i] = src[i];
        str[i + 1] = '\0';
    }
    return (str);
}
