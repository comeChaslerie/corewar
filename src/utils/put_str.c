/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** Write a null-terminated string to stdout
*/

#include "utils.h"
#include <unistd.h>

void put_str(char *str)
{
    write(1, str, my_strlen(str));
}
