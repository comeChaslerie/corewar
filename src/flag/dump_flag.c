/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "struct.h"
#include "game.h"
#include "dump.h"
#include <unistd.h>

void my_puthexa(unsigned char nbr, char *list_hexa)
{
    unsigned char list_hexa_len = NB_HEXA;

    if (nbr >= list_hexa_len)
        my_puthexa(nbr / list_hexa_len, list_hexa);
    write(1, &list_hexa[nbr % list_hexa_len], 1);
}

void print_arena(unsigned char *arena)
{
    for (unsigned int index = 0; index < (MEM_SIZE / 2); index++){
        if (arena[index] < NB_HEXA)
            write(1, ZERO_CHAR, 1);
        my_puthexa(arena[index], LIST_HEXA);
        if ((index + 1) % NB_BYTE_lINE == 0)
            write(1, NEW_LINE_CHAR, 1);
        else
            write(1, SPACE_CHAR, 1);
    }
}

void dump(main_t *main)
{
    print_arena(main->arena);
}
