/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** duplicates a string
*/
#include <stdlib.h>

unsigned char *my_ustrndup(unsigned char *src, unsigned int start,
    unsigned int end)
{
    unsigned char *str;
    unsigned int ulen = end - start;
    int len = end - start;

    if (!src || len < 0)
        return NULL;
    str = malloc(sizeof(char) * (ulen));
    if (!str)
        return NULL;
    for (unsigned int i = 0; i < ulen - 1; i++)
        str[i] = src[start + i];
    return (str);
}
