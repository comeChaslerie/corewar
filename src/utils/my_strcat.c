/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** add two strings in a new one
*/
#include <stdlib.h>
#include "my.h"

int fill_new_str(char *dest, char *src, char separator,
    char *new_str)
{
    int i = 0;

    for (int j = 0; dest[j] != '\0'; j++) {
        new_str[i] = dest[j];
        i += 1;
    }
    if (separator != '\0') {
        new_str[i] = separator;
        i += 1;
    }
    for (int j = 0; src[j] != '\0'; j++) {
        new_str[i] = src[j];
        i += 1;
    }
    return i;
}

char *my_strcat(char *dest, char *src, char separator)
{
    char *new_str = NULL;
    int i = 0;
    int len = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    if (separator != '\0')
        len = 1;
    new_str = malloc(sizeof(char) *
        (my_strlen(dest) + my_strlen(src) + 1) + len);
    if (new_str == NULL)
        return NULL;
    i = fill_new_str(dest, src, separator, new_str);
    new_str[i] = '\0';
    return new_str;
}
