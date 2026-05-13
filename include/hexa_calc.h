/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#ifndef HEXA_CALC_H
    #define HEXA_CALC_H

    #include <stdbool.h>

    #define HEXA_SIZE 8
    #define HEXA_MAX 15
    #define HEXA_MODULO 16

unsigned int uctoui(unsigned char *arg, int type);
unsigned char *uctohex(unsigned char *reg, int type);
bool hextouc(unsigned char *hex, unsigned char *reg);

bool hexa_diff(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

bool hexa_sum(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

bool hexa_and(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

bool hexa_or(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

bool hexa_xor(unsigned char **value1, unsigned char **value2,
    unsigned char **result);

#endif /* !HEXA_CALC_H */
