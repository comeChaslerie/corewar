/*
** EPITECH PROJECT, 2025
** linked_list
** File description:
** basic functions for a linked list
*/

#include "linked_list.h"

void disp_list(linked_list_t *list, void (*disp_data)(void *))
{
    linked_list_t *temp = list;

    while (temp != NULL) {
        if (temp->data != NULL) {
            disp_data(temp->data);
        }
        temp = temp->next;
    }
}
