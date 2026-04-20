/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

typedef struct data_s {
    int id;
} data_t;

typedef struct linked_list_s {
    data_t *data;
    struct linked_list_s *prev;
    struct linked_list_s *next;
} linked_list_t;

#endif /* !MY_STRUCT_H_ */
