/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Parse all the args
*/
#include <stdbool.h>
#include <stdlib.h>
#include "op.h"
#include "utils.h"

bool check_id(unsigned char elem, unsigned int *size_elem,
    unsigned int *id_instr)
{
    if (elem > 15)
        return false;
    *size_elem = 1;
    *id_instr = (unsigned int)elem;
    return true;
}

static unsigned int find_params(char *bin)
{
    char *result = NULL;

    if (bin[0] == '0') {
        if (bin[1] == '0')
            return 0;
        return T_REG;
    }
    if (bin[1] == '1')
        return T_IND;
    return T_DIR;
}

static unsigned int *get_coding_byte_tab(unsigned char elem)
{
    char *bin = to_bin(elem);
    unsigned int *tab = malloc(sizeof(int) * 4);
    unsigned int pos = 0;

    if (tab == NULL)
        return put_error("Tab alloc failed.", NULL);
    for (unsigned int index = 0; index < 4; index++) {
        tab[index] = find_params(bin + index * 2);
    }
    return tab;
}

bool check_byte_code(unsigned char elem, unsigned int *size_elem,
    unsigned int id_instr)
{
    unsigned int *tab = get_coding_byte_tab(elem);
    unsigned int size = 0;
    unsigned int nbr_args = 0;

    if (tab == NULL)
        return false;
    for (unsigned int index; index < 4; index++) {
        if (tab[index] != 0) {
            size += tab[index];
            nbr_args += 1;
        }
    }
    free(tab);
    *size_elem = size;
    if (nbr_args != op_tab[id_instr].nbr_args)
        return false;
    return true;
}

bool check_args(unsigned char *elem, unsigned int *size_elem)
{
    return true;
}
