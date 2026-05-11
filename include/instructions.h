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

bool live_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool load_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool store_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool add_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool sub_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool bin_and_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool bin_or_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool bin_xor_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool jump_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool load_ind_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool store_ind_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool fork_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool load_long_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool load_long_ind_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool fork_long_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);
bool print_instr(void *main, arg_t *args[MAX_ARGS_NUMBER],
    unsigned int robot_id);

#endif /* !INSTRUCTIONS_H_ */
