/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** duplicates a string
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char *src)
{
    char *str;
    int i = 0;
    int len;

    if (src == NULL)
        return NULL;
    len = my_strlen(src);
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return NULL;
    while (i < len) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *my_strndup(char *src, int start, int end)
{
    char *str;
    int i = 0;
    int len = end - start;

    if (src == NULL || len < 0)
        return NULL;
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return NULL;
    while (i < len) {
        str[i] = src[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}
