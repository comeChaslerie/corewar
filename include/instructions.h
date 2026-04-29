/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include "struct.h"
    #include <stdbool.h>

bool live_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool load_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool store_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool add_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool sub_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool bin_and_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool bin_or_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool bin_xor_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool jump_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool load_ind_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool store_ind_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool fork_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool load_long_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool load_long_ind_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool fork_long_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);
bool print_instr(void *main, arg_t *args[MAX_ARGS_NUMBER]);

#endif /* !INSTRUCTIONS_H_ */
