/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "struct.h"
#include "init.h"
#include "game.h"
#include "op.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

static char size_to_type(unsigned int size, bool is_index)
{
    if (size == REG_ARG_SIZE)
        return T_REG;
    if (size == DIR_SIZE)
        return T_DIR;
    if (is_index)
        return T_DIR;
    return T_IND;
}

static bool fill_instr(unsigned int *args_tab,
    instr_t *instr, unsigned char *args)
{
    unsigned int start = 0;
    bool is_index = op_tab[(int)instr->id].is_index;
    char type;

    if (!args_tab){
        instr->args[0] = init_arg(args, op_tab[(int)instr->id].type[0],
            get_size_from_id(instr->id));
        if (!instr->args[0])
            return false;
        return true;
    }
    for (unsigned int i = 0; args_tab[i]; i++){
        type = size_to_type(args_tab[i], is_index);
        instr->args[i] = init_arg(&(args[start]), type, args_tab[i]);
        if (!instr->args[i])
            return false;
        start += args_tab[i];
    }
    return true;
}

instr_t *translate_mem(unsigned char *instr)
{
    instr_t *new_instr = init_instr();
    unsigned int *args_tab = NULL;
    unsigned char start = instr[1];

    if (!new_instr || !instr)
        return NULL;
    new_instr->id = instr[0];
    if (op_tab[(int)new_instr->id].coding_byte)
        args_tab = get_coding_byte_tab(instr[1], new_instr->id);
    if (args_tab)
        start = instr[2];
    if (!fill_instr(args_tab, new_instr, &start)){
        free_values((void *[4]){(void *)new_instr->args[0],
                (void *)new_instr->args[1], (void *)new_instr->args[2],
                (void *)new_instr}, 4);
        return NULL;
    }
    if (args_tab)
        free(args_tab);
    return new_instr;
}
