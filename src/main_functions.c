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

static int display_help(void)
{
    put_str("USAGE\n");
    put_str("./corewar [-dump nbr_cycle] [[-n prog_number]"
        " [-a load_address] prog_name] ...\n");
    put_str("DESCRIPTION\n");
    put_str("-dump nbr_cycle dumps the state of the virtual"
        " machine after the nbr_cycle execution\n");
    put_str("-n prog_number sets the next program's number."
        " By default, the first free number in the parameter"
        " order\n");
    put_str("-a load_address sets the next program's loading"
        " address. When no address is specified, optimize the"
        " addresses so that the processes are as far away"
        " from each other as possible. The addresses are"
        " MEM_SIZE modulo.\n");
    return 0;
}

int main_functions(int argc, char **argv)
{
    args_t *args = NULL;
    main_t *main = NULL;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return display_help();
    args = parse_args(argc, argv);
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
