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

static bool fill_instr(unsigned int *args_size, unsigned int arg_size,
    instr_t *instr, unsigned char *args)
{
    unsigned int start = 0;

    if (arg_size){
        instr->args[0] = init_arg(args, (char)arg_size);
        if (!instr->args[0])
            return false;
        return true;
    }
    for (unsigned int i = 0; args_size[i]; i++){
        instr->args[i] = init_arg(&(args[start]), args_size[i]);
        if (!instr->args[i])
            return false;
    }
    return true;
}

instr_t *translate_mem(unsigned char *instr)
{
    instr_t *new_instr = init_instr();
    unsigned int *args_size = NULL;
    unsigned int arg_size = 0;

    if (!new_instr || !instr)
        return NULL;
    new_instr->id = instr[0];
    if (op_tab[(int)new_instr->id].coding_byte)
        args_size = get_coding_byte_tab(instr[1], new_instr->id);
    else
        arg_size = get_size_from_id(instr[0]);
    if (!fill_instr(args_size, arg_size, new_instr, &(instr[1]))){
        free_values((void *[4]){(void *)new_instr->args[0],
            (void *)new_instr->args[1], (void *)new_instr->args[2],
            (void *)new_instr}, 4);
        return NULL;
    }
    if (args_size)
        free(args_size);
    return new_instr;
}
