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
bool apply_cycle(main_t *main);
instr_t *translate_mem(unsigned char *instr);
unsigned int get_size_from_id(unsigned int instr_id);
unsigned int *get_coding_byte_tab(unsigned char elem, unsigned int id_instr);
unsigned int get_global_size(unsigned int *tab, unsigned int *nbr_args);
bool game_loop(main_t *main);
void display_winner(robot_infos_t *winner);
unsigned char *get_arg_content(arg_t *arg, unsigned int robot_id, main_t *main);
unsigned int get_u_arg_content(arg_t *arg, unsigned int robot_id, main_t *main);

#endif
