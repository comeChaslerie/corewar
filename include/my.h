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
    #include "lib.h"
    #include <stdio.h>
    #include <stdbool.h>

void display_hello(void);

bool check_magic_champions(header_t *header);
int get_champion_infos(FILE *fp);
void get_args(unsigned char value);

#endif /* !MY_H_ */
