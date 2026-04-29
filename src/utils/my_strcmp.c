/*
** EPITECH PROJECT, 2025
** my_strcmp.c
** File description:
** compare strings
*/
#include <stdlib.h>

int my_strcmp(char *s1, char *s2)
{
    int i1 = 0;
    int i2 = 0;

    if (s1 == NULL)
        return 0;
    if (s2 == NULL)
        return 0;
    while (s1[i1] != '\0' && s2[i2] != '\0') {
        if (s1[i1] != s2[i2]) {
            return s1[i1] - s2[i2];
        }
        i1++;
        i2++;
    }
    return s1[i1] - s2[i2];
}

int my_strncmp(char *s1, char *s2, int end)
{
    int i1 = 0;
    int i2 = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    if (end == 0)
        return 0;
    while (s1[i1] != '\0' && s2[i2] != '\0' && i1 < (end - 1)) {
        if (s1[i1] != s2[i2]) {
            return s1[i1] - s2[i2];
        }
        i1++;
        i2++;
    }
    return s1[i1] - s2[i2];
}
