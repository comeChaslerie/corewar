/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** main_functions
*/
#include "op.h"
#include "parse_args.h"
#include "struct.h"
#include "utils.h"
#include <stdlib.h>

void *free_main(char *str, main_t *main, args_t *args)
{
    put_error(str, NULL);
    if (main == NULL)
        return free_args_struct(args);
    if (main->arena != NULL)
        free(main->arena);
    //if (main->robots != NULL)
    //    free_robots();
    free(main);
    return free_args_struct(args);
}

robot_infos_t *init_robots()
{
    robot_infos_t *robot_infos = malloc(sizeof(robot_infos_t));

    if (robot_infos == NULL)
        return put_error("Robot infos alloc failed.", NULL);
    return robot_infos;
}

main_t *init_main(args_t *args)
{
    main_t *main = malloc(sizeof(main_t));

    if (main == NULL)
        return put_error("Main alloc failed.", NULL);
    main->arena = malloc(sizeof(unsigned char) * (MEM_SIZE / 2));
    if (main->arena == NULL)
        return free_main("Arena alloc failed.", main, args);
    main->robots = init_robots();
    if (main->robots == NULL)
        return free_main("Robots alloc failed.", main, args);
    main->cycle = 0;
    main->cycle_dump = args->cycle_dump;
    main->nbr_robots = args->nbr_robots;
    free_args_struct(args);
    return main;
}
