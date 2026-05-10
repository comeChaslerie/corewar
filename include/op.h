/*
** EPITECH PROJECT, 2025
** asm
** File description:
** Header for the operations
*/

#ifndef OP_H_
    #define OP_H_

    #include "struct.h"
    #include "define.h"
    #include <stdbool.h>

typedef char args_type_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
    bool coding_byte;
    bool is_index;
    bool (*instr_func)(void *, arg_t *[MAX_ARGS_NUMBER], unsigned int);
} op_t;

/*
** op_tab
*/
extern const op_t op_tab[];

#endif /* OP_H_ */
