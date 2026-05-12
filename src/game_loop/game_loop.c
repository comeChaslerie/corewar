/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdbool.h>
#include "struct.h"
#include "game.h"
#include "utils.h"
#include <unistd.h>

bool game_loop(main_t *main)
{
    if (!main)
        return put_error("incorrect arg in game_loop\n", false);
    for (unsigned int i = 0; i < CYCLE_TO_DIE; i++){
        if (!apply_cycle(main))
            return put_error("instr apply fail", false);
        if (main->cycle_dump == i)
            dump(main);
    }
    return true;
}
