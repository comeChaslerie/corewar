/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** init main struct with args struct
*/

#include "parse_args.h"
#include "struct.h"
#include "utils.h"
#include "handle_main.h"
#include <stdlib.h>

bool init_game_infos(robot_infos_t *robot_infos)
{
    robot_infos->game_infos = malloc(sizeof(robot_game_infos_t));
    if (robot_infos->game_infos == NULL)
        return false;
    robot_infos->game_infos->regs = malloc(sizeof(int) * REG_NUMBER);
    if (robot_infos->game_infos->regs == NULL)
        return false;
    robot_infos->game_infos->carry = 0;
    robot_infos->game_infos->pc = 0;
    robot_infos->game_infos->cycles_remaining = 0;
    return true;
}

bool init_one_robot(robot_infos_t *robot_infos, robot_args_t *robot_args,
    main_t *main)
{
    if (!init_game_infos(robot_infos))
        return put_error("Game alloc failed.", false);
    robot_infos->id = robot_args->id;
    robot_infos->pos_infos = malloc(sizeof(pos_infos_t));
    if (robot_infos->pos_infos == NULL)
        return put_error("Pos alloc failed.", false);
    robot_infos->pos_infos->pos_start = robot_args->load_pos;
    robot_infos->pos_infos->pos_end = 0;
    robot_infos->pos_infos->pos_next_instr = robot_args->load_pos;
    if (!fill_robot_instr(main, robot_infos, robot_args))
        return put_error("Fill robot failed.", false);
    return true;
}

robot_infos_t *init_robots(args_t *args, main_t *main)
{
    robot_infos_t *robot_infos = malloc(sizeof(robot_infos_t) *
        args->nbr_robots);

    if (robot_infos == NULL)
        return put_error("Robot infos alloc failed.", NULL);
    for (unsigned int index = 0; index < args->nbr_robots; index++) {
        printf("index_robot: %i\n\n", index);
        if (!init_one_robot(&robot_infos[index],
            &args->robots_args[index], main))
            return put_error("One robot init failed.", NULL);
    }
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
    main->robots = init_robots(args, main);
    if (main->robots == NULL)
        return free_main("Robots alloc failed.", main, args);
    main->cycle = 0;
    main->cycle_dump = args->cycle_dump;
    main->nbr_robots = args->nbr_robots;
    free_args_struct(args);
    return main;
}
