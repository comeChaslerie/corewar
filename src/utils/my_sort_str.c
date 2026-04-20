/*
** EPITECH PROJECT, 2025
** my_str_sort
** File description:
** sort a word array
*/
#include <stdlib.h>
#include "my.h"

void swap_str(char **tab, int j)
{
    char *temp = NULL;

    if (my_strcmp(tab[j], tab[j + 1]) > 0) {
        temp = tab[j];
        tab[j] = tab[j + 1];
        tab[j + 1] = temp;
    }
}

void my_sort_str(char **tab, int nb)
{
    for (int i = 0; i < nb - 1; i++) {
        for (int j = 0; j < nb - i - 1; j++) {
            swap_str(tab, j);
        }
    }
}
