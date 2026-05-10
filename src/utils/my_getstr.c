/*
** EPITECH PROJECT, 2025
** my_intlen
** File description:
** Return len of an integer
*/
#include "utils.h"
#include <stdlib.h>

char *my_getstr(unsigned int nbr)
{
    char *str = malloc(sizeof(char) * (my_intlen_u(nbr) + 1));
    int index = my_intlen_u(nbr) - 1;

    if (str == NULL)
        return NULL;
    str[my_intlen_u(nbr)] = '\0';
    if (nbr == 0)
        str[0] = '0';
    while (nbr != 0){
        str[index] = (nbr % 10) + '0';
        nbr = nbr / 10;
        index--;
    }
    return str;
}
