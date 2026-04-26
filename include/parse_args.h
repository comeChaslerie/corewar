/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef PARSE_ARGS_H_
    #define PARSE_ARGS_H_

    #include "struct.h"
    #include "op.h"
    #include <stdio.h>
    #include <stdbool.h>

void display_hello(void);

args_t *parse_args(int argc, char **argv);

args_t *alloc_args(void);
void *free_args_struct(args_t *args);

bool check_magic_champions(header_t *header);
int get_champion_infos(FILE *fp);
void get_args(unsigned char value);

bool manage_flags_robot(char **argv, unsigned int *index,
    unsigned int *robot_index, args_t *args);
bool manage_flag_id(int argc, char **argv, unsigned int *index,
    robot_args_t *robots_args);
bool manage_flag_load(int argc, char **argv, unsigned int *index,
    robot_args_t *robots_args);
bool manage_flag_dump(int argc, char **argv, unsigned int *index,
    args_t *args);

#endif /* !MY_H_ */
