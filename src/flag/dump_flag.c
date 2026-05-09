/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "struct.h"
#include "game.h"
#include <unistd.h>

void my_puthexa(unsigned char nbr, char *list_hexa)
{
    unsigned char list_hexa_len = 0;

    while (list_hexa[list_hexa_len])
        list_hexa_len++;
    if (nbr >= list_hexa_len)
        my_puthexa(nbr / list_hexa_len, list_hexa);
    write(1, &list_hexa[nbr % list_hexa_len], 1);
}

void print_arena(unsigned char *arena)
{
    for (unsigned int i = 0; i < (MEM_SIZE / 2); i++){
        if (arena[i] < 16)
            write(1, "0", 1);
        my_puthexa(arena[i], "0123456789abcdef");
        if ((i + 1) % 32 == 0)
            write(1, "\n", 1);
        else
            write(1, " ", 1);
    }
}

void dump(main_t *main)
{
    print_arena(main->arena);
}
