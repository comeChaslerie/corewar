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

typedef struct robot_infos_s {
    header_t *header;
    int regs[REG_NUMBER];
    int cycles_remaining;
    bool carry;
    int pc;
    int pos_next_instr;
    int pos_start;
    int pos_end;
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
    args_t args;
    unsigned char arena[MEM_SIZE / 2];
    robot_infos_t robots[MAX_ROBOT_NBR];
    int cycle;
} main_t;

#endif
