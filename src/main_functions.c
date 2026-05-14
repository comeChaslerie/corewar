/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** main_functions
*/
#include "struct.h"
#include "parse_args.h"
#include "handle_main.h"
#include "game.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

static int handle_solo_robot(main_t *main, args_t *args)
{
    write(1, "Your robot is alone...\n", 23);
    display_winner(&main->robots[0]);
    free_main(main, args);
    return 0;
}

int main_functions(int argc, char **argv)
{
    args_t *args = parse_args(argc, argv);
    main_t *main = NULL;

    if (args == NULL)
        return 84;
    main = init_main(args);
    if (main == NULL)
        return 84;
    if (main->nbr_robots == 1)
        return handle_solo_robot(main, args);
    if (!game_loop(main)){
        free_main(main, args);
        put_error("game loop failed.\n", NULL);
        return 84;
    }
    free_main(main, args);
    return 0;
}
