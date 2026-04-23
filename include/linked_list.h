/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/
#ifndef MY_LIB_H_
    #define MY_LIB_H_

    #include <stdio.h>
    #include <stdbool.h>


typedef struct linked_list_s {
    void *data;
    struct linked_list_s *prev;
    struct linked_list_s *next;
} linked_list_t;

int get_len_list(linked_list_t *list);
bool add_head(linked_list_t **list, void *data);
bool add_tail(linked_list_t **list, void *data);
void delete_node(linked_list_t *temp, linked_list_t **list,
    void(*destroy_data)(void *));
void disp_list(linked_list_t *list, void (*disp_data)(void *));
void destroy_list(linked_list_t *list, void(*destroy_data)(void *));

#endif /* !MY_LIB_H_ */
