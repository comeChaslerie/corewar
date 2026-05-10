/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "op.h"
#include "define.h"

unsigned int get_size_from_id(unsigned int instr_id)
{
    char ctype = op_tab[instr_id].type[0];

    if (ctype == T_DIR && op_tab[instr_id].is_index)
        return IND_SIZE;
    if (ctype == T_IND)
        return IND_SIZE;
    if (ctype == T_REG)
        return REG_ARG_SIZE;
    return DIR_SIZE;
}
