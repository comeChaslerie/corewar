/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdlib.h>
#include "struct.h"
#include "utils.h"

instr_t *init_instr(void)
{
    instr_t *instr = malloc(sizeof(instr_t) * 1);

    if (!instr)
        return put_error("Error: malloc in init_instr.\n", NULL);
    for (unsigned int i = 0; i < MAX_ARGS_NUMBER; i++) {
        instr->args[i] = NULL;
    }
    instr->id = 0;
    return instr;
}
