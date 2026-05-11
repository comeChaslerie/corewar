/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdlib.h>

void free_values(void **values, unsigned int nb_values)
{
    for (unsigned int i = 0; i < nb_values; i++){
        if (values[i]){
            free(values[i]);
            values[i] = NULL;
        }
    }
}
