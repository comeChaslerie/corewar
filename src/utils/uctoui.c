/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "utils.h"

unsigned int uctoui(unsigned char *arg, int type)
{
    unsigned int result = 0;
    unsigned int pow = 1;
    unsigned int size = get_type_size(type);

    for (unsigned int i = size; i > 0; i--){
        result += arg[i - 1] * pow;
        pow *= 256;
    }
    return result;
}
