/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

    #include "op.h"
    #include <stdbool.h>

typedef struct pos_infos_s {
    int pos_next_instr;
    int pos_start;
    int pos_end;
} pos_infos_t;

typedef struct robot_infos_s {
    header_t *header;
    unsigned int id;
    int regs[REG_NUMBER];
    int cycles_remaining;
    bool carry;
    int pc;
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
