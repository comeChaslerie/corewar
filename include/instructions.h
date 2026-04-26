/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include "op.h"
    #include <stdbool.h>

bool live_instr(void *value);
bool load_instr(void *value);
bool store_instr(void *value);
bool add_instr(void *value);
bool sub_instr(void *value);
bool bin_and_instr(void *value);
bool bin_or_instr(void *value);
bool bin_xor_instr(void *value);
bool jump_instr(void *value);
bool load_ind_instr(void *value);
bool store_ind_instr(void *value);
bool fork_instr(void *value);
bool load_long_instr(void *value);
bool load_long_ind_instr(void *value);
bool fork_long_instr(void *value);
bool live_instr(void *value);
bool live_instr(void *value);
bool print_instr(void *value);


#endif /* !MY_H_ */
