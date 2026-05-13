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

static void kill_robots(main_t *main)
{
    for (unsigned int i = 0; i < main->nbr_robots; i++)
        main->robots[i].game_infos->alive = main->robots[i].live;
}

bool game_loop(main_t *main)
{
    unsigned int cycles_to_die = CYCLE_TO_DIE;

    if (!main)
        return put_error("incorrect arg in game_loop\n", false);
    for (unsigned int i = 0; i < cycles_to_die; i++){
        if (!apply_cycle(main))
            return put_error("instr apply fail", false);
        if (main->cycle_dump == i)
            dump(main);
        if (i != 0 && (i % cycles_to_die) == 0)
            kill_robots(main);
        if (main->nb_live >= NBR_LIVE){
            cycles_to_die -= CYCLE_DELTA;
            main->nb_live %= NBR_LIVE;
        }
    }
    return true;
}
