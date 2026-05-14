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

static void print_index_hexa(unsigned int index, unsigned int i)
{
    if (i < 8) {
        print_index_hexa(index / NB_HEXA, i + 1);
        write(1, &LIST_HEXA[index % NB_HEXA], 1);
    }
}

static void print_arena(unsigned char *arena)
{
    for (unsigned int index = 0; index < MEM_SIZE; index++){
        if (index % NB_BYTE_LINE == 0) {
            print_index_hexa(index, 0);
            write(1, COLON_CHAR, 1);
            write(1, SPACE_CHAR, 1);
        }
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
        if (index < NB_BYTE_LINE - 1)
            write(1, SPACE_CHAR, 1);
    }
    write(1, NEW_LINE_CHAR, 1);
    for (unsigned int i = 0; i < NB_BYTE_LINE + SIZE_INDEX; i++) {
        if (i < SIZE_BEFORE_SEP)
            write(1, SPACE_CHAR, 1);
        if (i >= SIZE_BEFORE_SEP)
            write(1, SEPARATOR_MEMORY, 2);
        if (i >= SIZE_BEFORE_SEP && i < NB_BYTE_LINE + SIZE_INDEX - 1)
            write(1, SPACE_CHAR, 1);
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

static void print_register(unsigned char **regs, unsigned int nb_spaces)
{
    for (unsigned int i = 0; i < NB_REG; i++) {
        for (unsigned int j = 0; j < nb_spaces; j++)
            write(1, SPACE_CHAR, 1);
        write(1, REGISTER_LETTER, 1);
        my_put_nbr_u(i + 1);
        if (i < 9)
            write(1, SPACE_CHAR, 1);
        write(1, COLON_CHAR, 1);
        write(1, SPACE_CHAR, 1);
        print_index_hexa(regs[i][0], 1);
        if ((i + 1) % NB_REG_LINE == 0)
            write(1, NEW_LINE_CHAR, 1);
    }
    write(1, NEW_LINE_CHAR, 1);
}

static void print_child(robot_infos_t *child, unsigned int parent_id)
{
    if (child) {
        write(1, SPACE_CHAR, 1);
        print_robot_name(child);
        print_register(child->game_infos->regs, NB_SPACE_CHILD);
        for (unsigned int j = 0; j < NB_SPACE_CHILD; j++)
            write(1, SPACE_CHAR, 1);
        write(1, "PC : ", 5);
        print_index_hexa(child->game_infos->pc, 1);
        for (unsigned int j = 0; j < NB_SPACE_CHILD; j++)
            write(1, SPACE_CHAR, 1);
        write(1, "carry: ", 7);
        my_puthexa(child->game_infos->carry);
        write(1, NEW_LINE_CHAR, 1);
        print_child(child->child, parent_id);
    }
}

static void print_robot(main_t *main)
{
    write(1, "Registers:", 10);
    write(1, NEW_LINE_CHAR, 1);
    for (unsigned int i = 0; i < main->nbr_robots; i++) {
        print_robot_name(&main->robots[i]);
        print_register(main->robots[i].game_infos->regs, NB_SPACE);
        for (unsigned int j = 0; j < NB_SPACE; j++)
            write(1, SPACE_CHAR, 1);
        write(1, "PC : ", 5);
        print_index_hexa(main->robots[i].game_infos->pc, 1);
        for (unsigned int j = 0; j < NB_SPACE; j++)
            write(1, SPACE_CHAR, 1);
        write(1, "carry: ", 7);
        my_puthexa(main->robots[i].game_infos->carry);
        write(1, NEW_LINE_CHAR, 1);
        print_child(main->robots[i].child, i);
    }
    write(1, NEW_LINE_CHAR, 1);
}

void dump(main_t *main)
{
    print_cycle(main->total_cycles);
    print_robot(main);
    print_memory();
    print_arena(main->arena);
}
