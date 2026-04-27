/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "op.h"

unsigned int get_size_from_id(unsigned int instr_id)
{
    unsigned int size = 0;
    char csize = op_tab[instr_id].type[0];

    size = (unsigned int)csize;
    return size;
}
