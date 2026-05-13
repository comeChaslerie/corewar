/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "compute.h"
#include "define.h"
#include "utils.h"
#include <stdlib.h>

unsigned char *uctohex(unsigned char *reg, int type)
{
    unsigned char *hex = malloc(sizeof(unsigned char) * HEXA_SIZE);
    unsigned int i = 0;
    unsigned int size = get_type_size(type);

    if (!hex)
        return NULL;
    for (i = 0; i < REG_SIZE && i < size; i++){
        hex[2 * i] = reg[i] / 16;
        hex[2 * i + 1] = reg[i] % 16;
    }
    for (i = 2 * i; i < REG_SIZE; i++)
        hex[i] = 0;
    return hex;
}
