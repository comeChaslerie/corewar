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
typedef struct data_s {
    int id;
} data_t;

typedef struct linked_list_s {
    data_t *data;
    void *data_void;
    struct linked_list_s *prev;
    struct linked_list_s *next;
} linked_list_t;


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

typedef struct main_s {
    unsigned char arena[MEM_SIZE / 2];
    robot_infos_t robots[4];
    int cycle;
} main_t;

#endif /* !MY_STRUCT_H_ */
