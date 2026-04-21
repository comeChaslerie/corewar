/*
** EPITECH PROJECT, 2025
** Project_name
** File description:
** main_function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

char *find_params(char *bin)
{
    char *result = NULL;

    if (bin[0] == '0') {
        if (bin[1] == '0')
            return NULL;
        return strdup("register");
    }
    if (bin[1] == '1')
        return strdup("indirect");
    return strdup("direct");
}

void get_args(unsigned char value)
{
    char *bin = to_bin(value); 
    char *result = NULL;
    unsigned int pos = 0;

    printf("\nFor value: 0x%i\n", value);
    printf("\nBinaire: %s\n", bin);
    for (unsigned int nbr = 1; nbr <= 4; nbr++) {
        result = find_params(bin + pos);
        if (result == NULL) {
            printf("%i: 00\n", nbr);
        } else
            printf("%i: %.2s -> %s\n", nbr, bin + pos, result);
        pos += 2;
    }
}
