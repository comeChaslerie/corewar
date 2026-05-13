/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "compute.h"

unsigned int uctoui(unsigned char *arg, unsigned int size)
{
    unsigned int result = 0;
    unsigned int pow = 1;

    for (int i = (int)size - 1; i >= 0; i--){
        result += arg[i] * pow;
        pow *= 256;
    }
    return result;
}
