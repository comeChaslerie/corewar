/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "struct.h"
#include "utils.h"
#include <stdlib.h>

arg_t *init_arg(unsigned char *arg, char type)
{
    arg_t *new_arg = malloc(sizeof(arg_t) * 1);

    if (!new_arg)
        return put_error("Error: malloc in init_arg.\n", NULL);
    new_arg->arg = my_ustrndup(arg, 0, (unsigned int)type);
    if (!new_arg->arg){
        free(new_arg);
        return put_error("Error: malloc in init_arg.\n", NULL);
    }
    new_arg->type = type;
    return new_arg;
}
