/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdlib.h>
#include <stdbool.h>
#include "compute.h"

bool hexa_diff(unsigned char **value1, unsigned char **value2,
    unsigned char **result)
{
    unsigned char retain = 0;
    unsigned char nb = 0;
    unsigned char to_sub = 0;

    for (int i = HEXA_SIZE - 1; i >= 0; i--){
        nb = (*value1)[i];
        to_sub = (*value2)[i] + retain;
        if (nb < to_sub){
            (*result)[i] = nb + HEXA_MODULO - to_sub;
            retain = 1;
        } else {
            (*result)[i] = nb - to_sub;
            retain = 0;
        }
    }
    return true;
}
