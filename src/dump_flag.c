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

static void print_cycle(unsigned int cycle)
{
    write(1, "Cycle", 5);
    write(1, COLON_CHAR, 1);
    write(1, SPACE_CHAR, 1);
    if (cycle == 0)
        write(1, ZERO_CHAR, 1);
    else
        my_put_nbr_u(cycle);
    write(1, NEW_LINE_CHAR, 1);
}

static void print_memory(void)
{
    write(1, "Memory:   ", SIZE_BEFORE_SEP);
    for (unsigned int index = 0; index < NB_BYTE_LINE; index++) {
        if (index < NB_HEXA)
            write(1, ZERO_CHAR, 1);
        my_puthexa(index);
        write(1, SPACE_CHAR, 1);
    }
    write(1, NEW_LINE_CHAR, 1);
    for (unsigned int i = 0; i < NB_BYTE_LINE + SIZE_INDEX; i++) {
        if (i < SIZE_BEFORE_SEP)
            write(1, SPACE_CHAR, 1);
        if (i == NB_BYTE_LINE + SIZE_INDEX)
            write(1, SEPARATOR_MEMORY, 2);
        if (i >= SIZE_BEFORE_SEP) {
            write(1, SEPARATOR_MEMORY, 2);
            write(1, SPACE_CHAR, 1);
        }
    }
    write(1, NEW_LINE_CHAR, 1);
}

static void print_robot_name(robot_infos_t *robots)
{
    write(1, SPACE_CHAR, 1);
    write(1, SPACE_CHAR, 1);
    write(1, robots->header.prog_name, my_strlen(robots->header.prog_name));
    write(1, OPEN_PARENTHESE, 1);
    my_put_nbr_u(robots->id);
    write(1, CLOSE_PARENTHESE, 1);
    write(1, COLON_CHAR, 1);
    write(1, SPACE_CHAR, 1);
    if (robots->game_infos->alive == true)
        write(1, "alive", 5);
    write(1, NEW_LINE_CHAR, 1);
}

static void print_register(unsigned char **regs)
{
    char register_value[9] = "000000000";

    for (unsigned int i = 0; i < NB_REG; i++) {
        for (unsigned int j = 0; j < NB_SPACE; j++)
            write(1, SPACE_CHAR, 1);
        write(1, REGISTER_LETTER, 1);
        my_put_nbr_u(i);
        if (i < 10)
            write(1, SPACE_CHAR, 1);
        write(1, COLON_CHAR, 1);
        write(1, SPACE_CHAR, 1);
        print_index_hexa(regs[i][0], register_value);
    }
    write(1, NEW_LINE_CHAR, 1);
}

static void print_robot(main_t *main)
{
    char index_pc[9] = "00000000";

    write(1, "Registers:", 10);
    write(1, NEW_LINE_CHAR, 1);
    for (unsigned int i = 0; i < main->nbr_robots; i++) {
        print_robot_name(&main->robots[i]);
        print_register(main->robots[i].game_infos->regs);
        for (unsigned int j = 0; j < NB_SPACE; j++)
            write(1, SPACE_CHAR, 1);
        write(1, "PC : ", 5);
        print_index_hexa(main->robots[i].game_infos->pc, index_pc);
        for (unsigned int j = 0; j < NB_SPACE; j++)
            write(1, SPACE_CHAR, 1);
        write(1, "carry: ", 7);
        my_puthexa(main->robots[i].game_infos->carry);
        write(1, NEW_LINE_CHAR, 1);
    }
}

void dump(main_t *main)
{
    print_cycle(main->cycle);
    print_robot(main);
    print_memory();
    print_arena(main->arena);
}
