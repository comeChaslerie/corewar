/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** add two strings in a new one
*/
#include "utils.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

unsigned char *my_ustrcat(unsigned char *dest, unsigned int *size_dest,
    unsigned char *src, unsigned int size_src)
{
    int i = *size_dest;
    size_t total_size = (size_t)*size_dest + (size_t)size_src;

    if ((dest == NULL && *size_dest != 0) ||
        (src == NULL && size_src != 0))
        return NULL;
    printf("size dest: %i\tsize src: %i\n", *size_dest, size_src);
    dest = realloc(dest, sizeof(unsigned char) * total_size);
    if (!dest)
        return put_error("realloc failed in my_ustrcat\n", NULL);
    for (int j = 0; j < size_src; j++) {
        dest[i] = src[j];
        i += 1;
    }
    *size_dest += size_src;
    return dest;
}
