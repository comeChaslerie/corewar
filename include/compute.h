/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#ifndef COMPUTE_H
    #define COMPUTE_H

    #include <stdbool.h>

    #define HEXA_SIZE 8
    #define HEXA_MAX 15
    #define HEXA_MODULO 16

unsigned int uctoui(unsigned char *arg, unsigned int size);
unsigned char *uctohex(unsigned char *reg, int type);
bool hextouc(unsigned char *hex, unsigned char *reg);

bool hexa_diff(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

bool hexa_sum(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

bool bin_and(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

bool bin_or(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

bool bin_xor(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

#endif /* !COMPUTE_H */
