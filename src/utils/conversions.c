/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Parse all the args
*/
#include <stdbool.h>
#include <stdlib.h>

char *to_bin(unsigned char value)
{
    char *bin = malloc(sizeof(char) * 9);

    for (int index = 7; index >= 0; index--) {
        if (value % 2 == 0)
            bin[index] = '0';
        if (value % 2 == 1)
            bin[index] = '1';
        value /= 2;
    }
    bin[8] = '\0';
    return bin;
}
