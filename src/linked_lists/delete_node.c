/*
** EPITECH PROJECT, 2025
** linked_list
** File description:
** basic functions for a linked list
*/

#include "linked_list.h"
#include <stdlib.h>

void delete_node(linked_list_t *temp, linked_list_t **list,
    void(*destroy_data)(void *))
{
    if (temp->prev == NULL) {
        *list = temp->next;
        if (temp->next != NULL)
            temp->next->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }
    destroy_data(temp->data);
    free(temp);
}
