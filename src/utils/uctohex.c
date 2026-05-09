/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "hexa_calc.h"
#include "op_define.h"
#include <stdlib.h>

unsigned char *uctohex(unsigned char *reg)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);

    if (!hex)
        return NULL;
    for (unsigned int i = 0; i < REG_SIZE; i++){
        hex[2 * i] = reg[i] / 16;
        hex[2 * i + 1] = reg[i] % 16;
    }
    return hex;
}
