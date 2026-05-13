/*
** EPITECH PROJECT, 2025
** linked_list
** File description:
** basic functions for a linked list
*/

#include "linked_list.h"

int get_len_list(linked_list_t *list)
{
    linked_list_t *temp = list;
    int len = 0;

    while (temp != NULL) {
        temp = temp->next;
        len += 1;
    }
    return len;
}
