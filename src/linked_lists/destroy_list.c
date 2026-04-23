/*
** EPITECH PROJECT, 2025
** linked_list2
** File description:
** sorting a linked list
*/

#include "linked_list.h"

void destroy_list(linked_list_t *list, void(*destroy_data)(void *))
{
    linked_list_t *tmp = list;
    linked_list_t *next = NULL;

    while (tmp){
        next = tmp->next;
        if (tmp->data)
            destroy_data(tmp->data);
        free(tmp);
        tmp = next;
    }
}
