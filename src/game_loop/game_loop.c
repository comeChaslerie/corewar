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
        if (!apply_instructions(main))
            return put_error("instr apply fail\n", false);
        if (main->cycle_dump == i)
            write(1, "dump\n", 6);
    }
    return true;
}
