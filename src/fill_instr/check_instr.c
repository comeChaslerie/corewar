/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Parse all the args
*/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "op.h"
#include "define.h"
#include "utils.h"

bool check_id(unsigned char elem, unsigned int *size_elem,
    unsigned int *id_instr)
{
    *id_instr = (unsigned int)elem;
    if (*id_instr > 15)
        return false;
    if (op_tab[(int) *id_instr].coding_byte)
        *size_elem = 1;
    else
        *size_elem = get_size_from_id(elem);
    return true;
}

static unsigned int find_params(char *bin, unsigned int id_instr)
{
    char *result = NULL;

    if (bin[0] == '0') {
        if (bin[1] == '0')
            return 0;
        return REG_SIZE;
    }
    if (bin[1] == '1')
        return IND_SIZE;
    if (op_tab[id_instr].is_index)
        return IND_SIZE;
    return DIR_SIZE;
}

unsigned int *get_coding_byte_tab(unsigned char elem, unsigned int id_instr)
{
    char *bin = to_bin(elem);
    unsigned int *tab = malloc(sizeof(int) * MAX_ARGS_NUMBER);
    unsigned int pos = 0;

    if (tab == NULL)
        return put_error("Tab alloc failed.", NULL);
    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++)
        tab[index] = find_params(bin + index * 2, id_instr);
    free(bin);
    return tab;
}

unsigned int get_global_size(unsigned int *tab, unsigned int *nbr_args)
{
    unsigned int size = 0;

    for (unsigned int index = 0; index < MAX_ARGS_NUMBER; index++) {
        if (tab[index] != 0) {
            size += tab[index];
            *nbr_args += 1;;
        }
    }
    return size;
}

bool check_byte_code(unsigned char elem, unsigned int *size_elem,
    unsigned int id_instr)
{
    unsigned int *tab = get_coding_byte_tab(elem, id_instr);
    unsigned int size = 0;
    unsigned int nbr_args = 0;

    if (tab == NULL)
        return put_error("Tab alloc failed.", false);
    size = get_global_size(tab, &nbr_args);
    free(tab);
    *size_elem = size;
    if (nbr_args != op_tab[id_instr].nbr_args)
        return put_error("Number of args differs from instr.", false);
    return true;
}

bool check_args(unsigned char *elem, unsigned int *size_elem)
{
    return true;
}
