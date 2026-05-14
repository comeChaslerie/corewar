/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/
#include <stdlib.h>
#include "struct.h"

void my_bzero(void *s, size_t n)
{
    char *p = s;
    for (size_t i = 0; i < n; i++)
        p[i] = 0;
}

arg_t *create_arg(char type, unsigned int size, unsigned char *data)
{
    arg_t *arg = malloc(sizeof(arg_t));
    arg->type = type;
    arg->size = size;
    arg->arg = data;
    return arg;
}

main_t *init_test_env(unsigned int robot_id)
{
    main_t *m = malloc(sizeof(main_t));

    my_bzero(m, sizeof(main_t));
    m->arena = malloc(MEM_SIZE);
    my_bzero(m->arena, MEM_SIZE);

    m->robots = malloc(sizeof(robot_infos_t) * MAX_ROBOT_NBR);
    my_bzero(m->robots, sizeof(robot_infos_t) * MAX_ROBOT_NBR);
    m->robots[robot_id].game_infos = malloc(sizeof(robot_game_infos_t));
    my_bzero(m->robots[robot_id].game_infos, sizeof(robot_game_infos_t));
    m->robots[robot_id].game_infos->regs = malloc(sizeof(unsigned char *) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++) {
        m->robots[robot_id].game_infos->regs[i] = malloc(REG_SIZE);
        my_bzero(m->robots[robot_id].game_infos->regs[i], REG_SIZE);
    }
    
    return m;
}
