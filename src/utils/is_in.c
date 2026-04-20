/*
** EPITECH PROJECT, 2025
** is_in
** File description:
** check if something is in something
*/
#include <stdlib.h>
#include "my.h"

int is_in_str(char *str, char letter)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == letter)
            return 1;
    }
    return 0;
}

int is_in_tab(char **tab, char *str)
{
    if (tab == NULL || str == NULL)
        return 0;
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], str) == 0)
            return 1;
    }
    return 0;
}
