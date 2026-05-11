/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

    #include <stdbool.h>
    #include "define.h"

typedef struct
header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    char padding[3];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
    char padding2[3];
} header_t;

typedef struct argument_s {
    char type;
    unsigned char *arg;
} arg_t;

typedef struct instruction_s {
    unsigned int id;
    arg_t *args[MAX_ARGS_NUMBER];
} instr_t;

typedef struct pos_infos_s {
    int pos_next_instr;
    int pos_start;
    int pos_end;
} pos_infos_t;

typedef struct robot_game_infos_s {
    int *regs;
    int cycles_remaining;
    bool carry;
    int pc;
    bool alive;
} robot_game_infos_t;

typedef struct robot_infos_s {
    header_t header;
    unsigned int id;
    robot_game_infos_t *game_infos;
    pos_infos_t *pos_infos;
} robot_infos_t;

typedef struct robot_args_s {
    char *filepath;
    int id;
    int load_pos;
} robot_args_t;

typedef struct args_s {
    int cycle_dump;
    robot_args_t *robots_args;
    unsigned int nbr_robots;
} args_t;

typedef struct main_s {
    unsigned char *arena;
    robot_infos_t *robots;
    unsigned int cycle;
    unsigned int cycle_dump;
    unsigned int nbr_robots;
} main_t;

#endif
