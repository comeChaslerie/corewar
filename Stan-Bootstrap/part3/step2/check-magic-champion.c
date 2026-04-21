/*
** EPITECH PROJECT, 2025
** Project_name
** File description:
** main_function
*/

#include "op.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_magic_champions(header_t *header)
{
    if (my_htonl(header->magic) == COREWAR_EXEC_MAGIC) {
        printf("Valid magic number!\n");
        return true;
    } else {
        printf("NOP!!!!");
        return false;
    }
}
