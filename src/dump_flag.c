/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "struct.h"
#include "game.h"
#include "define.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void my_puthexa(unsigned char nbr)
{
    if (nbr >= NB_HEXA)
        my_puthexa(nbr / NB_HEXA);
    write(1, &LIST_HEXA[nbr % NB_HEXA], 1);
}

static void print_index_hexa(unsigned int index, char *index_arena)
{
    for (int i = 7; i >= 0; i--) {
        index_arena[i] = LIST_HEXA[index % NB_HEXA];
        index /= NB_HEXA;
    }
    write(1, index_arena, 8);
    write(1, COLON_CHAR, 1);
    write(1, SPACE_CHAR, 1);
}

static void print_arena(unsigned char *arena)
{
    char index_arena[9] = "00000000";

    for (unsigned int index = 0; index < (MEM_SIZE); index++){
        if (index % NB_BYTE_LINE == 0)
            print_index_hexa(index, index_arena);
        if (arena[index] < NB_HEXA)
            write(1, ZERO_CHAR, 1);
        my_puthexa(arena[index]);
        if ((index + 1) % NB_BYTE_LINE == 0)
            write(1, NEW_LINE_CHAR, 1);
        else
            write(1, SPACE_CHAR, 1);
    }
}

static bool print_cycle(main_t *main)
{
    char *cycle = my_strdup(my_getstr(main->cycle));

    if (cycle == NULL)
        return false;
    write(1, "Cycle", 5);
    write(1, COLON_CHAR, 1);
    write(1, SPACE_CHAR, 1);
    write(1, cycle, my_strlen(cycle));
    write(1, NEW_LINE_CHAR, 1);
    free(cycle);
    return true;
}

static void print_memory(void)
{
    write(1, "Memory:   ", 10);
    for (unsigned int index = 0; index < NB_BYTE_LINE; index++) {
        if (index < NB_HEXA)
            write(1, ZERO_CHAR, 1);
        my_puthexa(index);
        write(1, SPACE_CHAR, 1);
    }
    write(1, NEW_LINE_CHAR, 1);
    for (unsigned int i = 0; i < NB_BYTE_LINE + SIZE_INDEX; i++) {
        if (i < 10)
            write(1, SPACE_CHAR, 1);
        if (i == NB_BYTE_LINE + SIZE_INDEX)
            write(1, SEPARATOR_MEMORY, 2);
        if (i >= 10) {
            write(1, SEPARATOR_MEMORY, 2);
            write(1, SPACE_CHAR, 1);
        }
    }
    write(1, NEW_LINE_CHAR, 1);
}

bool dump(main_t *main)
{
    if (!print_cycle(main))
        return false;
    print_memory();
    print_arena(main->arena);
    return true;
}
