/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** return an error
*/

#include <unistd.h>

int my_strlen(const char *str)
{
    unsigned int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}
