/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdbool.h>
#include "struct.h"
#include "game.h"
#include <unistd.h>
#include <stdio.h>

bool game_loop(main_t *main)
{
    if (!main)
        return false;
    for (unsigned int i = 0; i < CYCLE_TO_DIE; i++){
        if (!apply_instructions(main))
            return false;
        if (main->cycle_dump == i)
            printf("dump\n");
    }
    return true;
}
