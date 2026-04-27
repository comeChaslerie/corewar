/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

    #include <stdbool.h>
    #include "op_define.h"

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
