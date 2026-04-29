/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** add two strings in a new one
*/
#include <stdlib.h>

unsigned char *my_ustrcat(unsigned char *dest, unsigned int *size_dest,
    unsigned char *src, unsigned int size_src)
{
    unsigned char *new_str = NULL;
    int i = 0;

    if ((dest == NULL && *size_dest != 0) ||
        (src == NULL && size_src != 0))
        return NULL;
    new_str = malloc(sizeof(unsigned char) *
        (*size_dest + size_src));
    if (new_str == NULL)
        return NULL;
    for (int j = 0; j < *size_dest; j++) {
        new_str[i] = dest[j];
        i += 1;
    }
    for (int j = 0; j < size_src; j++) {
        new_str[i] = src[j];
        i += 1;
    }
    *size_dest += size_src;
    return new_str;
}
