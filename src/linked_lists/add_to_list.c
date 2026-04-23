/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "linked_list.h"
#include <stdbool.h>
#include <stdlib.h>

bool add_head(linked_list_t **list, void *data)
{
    linked_list_t *elem = malloc(sizeof(linked_list_t));

    if (elem == NULL)
        return false;
    elem->data = data;
    elem->prev = NULL;
    if (*list == NULL) {
        elem->next = NULL;
    } else {
        elem->next = *list;
        (*list)->prev = elem;
    }
    *list = elem;
    return true;
}

bool add_tail(linked_list_t **list, void *data)
{
    linked_list_t *elem = malloc(sizeof(linked_list_t));
    linked_list_t *temp = *list;

    if (elem == NULL || !data)
        return false;
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
    return true;
}
