/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "struct.h"
#include "game.h"
#include "define.h"
#include <unistd.h>

void my_puthexa(unsigned char nbr)
{
    if (nbr >= NB_HEXA)
        my_puthexa(nbr / NB_HEXA);
    write(1, &LIST_HEXA[nbr % NB_HEXA], 1);
}

void print_arena(unsigned char *arena)
{
    for (unsigned int index = 0; index < (MEM_SIZE / 2); index++){
        if (arena[index] < NB_HEXA)
            write(1, ZERO_CHAR, 1);
        my_puthexa(arena[index]);
        if ((index + 1) % NB_BYTE_LINE == 0)
            write(1, NEW_LINE_CHAR, 1);
        else
            write(1, SPACE_CHAR, 1);
    }
}

void dump(main_t *main)
{
    print_arena(main->arena);
}
