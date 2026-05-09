/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdlib.h>
#include <stdbool.h>
#include "hexa_calc.h"

bool hexa_diff(unsigned char **value1, unsigned char **value2,
    unsigned char **result)
{
    unsigned char retain = 0;

    for (unsigned int i = HEXA_SIZE - 1; i > 0; i++){
        (*result)[i] = (*value1)[i] - (*value2)[i] - retain;
        if ((*result)[i] > HEXA_MAX && i == HEXA_SIZE)
            return false;
        if ((*value1)[i] < (*value2)[i]){
            retain = 1;
            (*result)[i] += HEXA_MODULO;
        } else
            retain = 0;
    }
    return true;
}
