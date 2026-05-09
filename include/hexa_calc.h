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

bool hexa_diff(unsigned char *value1[8], unsigned char *value2[8],
    unsigned char *result[8]);

bool hexa_sum(unsigned char *value1[8], unsigned char *value2[8],
    unsigned char *result[8]);

#endif /* !HEXA_CALC_H */
