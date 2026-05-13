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

static bool is_finish_game(main_t *main)
{
    unsigned int nb_alive = 0;
    unsigned int last_alive = 0;

    for (unsigned int i = 0; i < main->nbr_robots; i++)
        if (main->robots[i].game_infos->alive){
            nb_alive++;
            last_alive = main->robots[i].id;
        }
    if (nb_alive == 1){
        write(1, "Player: ", 9);
        my_put_nbr_u(last_alive);
        write(1, " has win!\n", 11);
        return true;
    }
    if (!nb_alive){
        write(1, "Nobody wins...\n", 16);
        return true;
    }
    return false;
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
        if (is_finish_game(main))
            return true;
    }
    return true;
}
