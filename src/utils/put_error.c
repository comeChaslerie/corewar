/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** return an error
*/

#include "utils.h"
#include <unistd.h>

void *put_error(const char *str, void *return_value)
{
    write(2, str, my_strlen(str));
    write(2, "\n", 1);
    return return_value;
}
