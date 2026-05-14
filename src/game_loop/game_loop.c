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
    for (unsigned int i = 0; i < main->nbr_robots; i++){
        main->robots[i].game_infos->alive = main->robots[i].live;
        main->robots[i].live = false;
    }
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

static void reset_cycle(main_t *main, unsigned int *cycle,
    unsigned int cycle_to_die)
{
    kill_robots(main);
    *cycle %= cycle_to_die;
}

bool game_loop(main_t *main)
{
    unsigned int cycles_to_die = CYCLE_TO_DIE;

    if (!main)
        return put_error("incorrect arg in game_loop\n", false);
    for (unsigned int i = 0; cycles_to_die > 0; i++){
        if (!apply_cycle(main))
            return put_error("instr apply fail", false);
        if (main->cycle_dump == main->total_cycles)
            dump(main);
        if (main->nb_live >= NBR_LIVE){
            cycles_to_die -= CYCLE_DELTA;
            main->nb_live %= NBR_LIVE;
        }
        if (i != 0 && i >= cycles_to_die)
            reset_cycle(main, &i, cycles_to_die);
        if (is_finish_game(main))
            return true;
        main->total_cycles++;
    }
    kill_robots(main);
    is_finish_game(main);
    return true;
}
