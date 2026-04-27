/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "struct.h"
    #include <stdbool.h>

void dump(main_t *main);

int main_functions(int argc, char **argv);

bool apply_instructions(main_t *main);

bool check_function(unsigned char *);

unsigned int *get_args_size(unsigned char);

unsigned int get_global_size(unsigned int *args_size);

instr_t *translate_mem(unsigned char *instr);

unsigned int get_size_from_id(unsigned int instr_id);

#endif
