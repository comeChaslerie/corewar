/*
** EPITECH PROJECT, 2025
** linked_list2
** File description:
** sorting a linked list
*/
#include <stdlib.h>
#include "my.h"

void switch_datas(linked_list_t *temp1, linked_list_t *temp2)
{
    data_t *temp = temp1->data;

    temp1->data = temp2->data;
    temp2->data = temp;
}

void switch_id(linked_list_t *temp, int reverse)
{
    if (reverse == 1 && temp->next != NULL &&
        temp->data->id < temp->next->data->id)
        switch_datas(temp, temp->next);
    if (reverse == 0 && temp->next != NULL && temp->data->id >
        temp->next->data->id)
        switch_datas(temp, temp->next);
}

void sort_list(linked_list_t *list, int reverse,
    void (*sort_fct)(linked_list_t *, int))
{
    int len = get_len_list(list);
    linked_list_t *temp = list;
    int i = 0;

    while (len > 0) {
        while (temp->next != NULL && i < len) {
            sort_fct(temp, reverse);
            temp = temp->next;
            i += 1;
        }
        i = 0;
        while (temp->prev != NULL)
            temp = temp->prev;
        len -= 1;
    }
}
