/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdlib.h>
#include <stdbool.h>
#include "compute.h"

bool bin_and(unsigned char **value1, unsigned char **value2,
    unsigned char **result)
{
    for (unsigned int i = 0; i < HEXA_SIZE; i++){
        (*result)[i] = (*value1)[i] & (*value2)[i];
        if ((*result)[i] > HEXA_MAX && i == HEXA_SIZE)
            return false;
    }
    return true;
}
