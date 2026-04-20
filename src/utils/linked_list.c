/*
** EPITECH PROJECT, 2025
** linked_list
** File description:
** basic functions for a linked list
*/
#include <stdlib.h>
#include "struct.h"

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

int add_head(linked_list_t **list, data_t *data)
{
    linked_list_t *elem = malloc(sizeof(linked_list_t));

    if (elem == NULL)
        return 84;
    elem->data = data;
    elem->prev = NULL;
    if (*list == NULL) {
        elem->next = NULL;
    } else {
        elem->next = *list;
        (*list)->prev = elem;
    }
    *list = elem;
    return 0;
}

int add_tail(linked_list_t **list, data_t *data)
{
    linked_list_t *elem = malloc(sizeof(linked_list_t));
    linked_list_t *temp = *list;

    if (elem == NULL)
        return 84;
    elem->data = data;
    elem->next = NULL;
    if (*list == NULL) {
        elem->prev = NULL;
        *list = elem;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        elem->prev = temp;
        temp->next = elem;
    }
    return 0;
}

void delete_node(linked_list_t *temp, linked_list_t **list)
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
    free(temp->data);
    free(temp);
}

void disp_list(linked_list_t *list, void (*disp_data)(data_t *))
{
    linked_list_t *temp = list;

    while (temp != NULL) {
        if (temp->data != NULL) {
            disp_data(temp->data);
        }
        temp = temp->next;
    }
}
