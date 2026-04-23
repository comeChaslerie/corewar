/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef MY_H_
    #define MY_H_

    #include "struct.h"
    #include "op.h"
    #include <stdio.h>
    #include <stdbool.h>

void display_hello(void);

bool check_magic_champions(header_t *header);
int get_champion_infos(FILE *fp);
void get_args(unsigned char value);

void *live_instr(void *value);
void *load_instr(void *value);
void *store_instr(void *value);
void *add_instr(void *value);
void *sub_instr(void *value);
void *bin_and_instr(void *value);
void *bin_or_instr(void *value);
void *bin_xor_instr(void *value);
void *jump_instr(void *value);
void *load_ind_instr(void *value);
void *store_ind_instr(void *value);
void *fork_instr(void *value);
void *load_long_instr(void *value);
void *load_long_ind_instr(void *value);
void *fork_long_instr(void *value);
void *live_instr(void *value);
void *live_instr(void *value);
void *print_instr(void *value);


#endif /* !MY_H_ */
