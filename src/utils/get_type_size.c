/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include "define.h"

unsigned int get_type_size(int type)
{
    switch (type){
        case T_DIR:
            return DIR_SIZE;
        case T_IND:
            return IND_SIZE;
        case T_REG:
            return REG_ARG_SIZE;
        default:
            return 0;
    }
}
