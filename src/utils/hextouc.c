/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "op_define.h"
#include <stdlib.h>

unsigned char *hextouc(unsigned char *hex, unsigned char *reg)
{
    for (unsigned int i = 0; i < REG_SIZE; i++){
        reg[i] = hex[2 * i] * 16;
        reg[i] += hex[2 * i + 1];
    }
    return hex;
}
