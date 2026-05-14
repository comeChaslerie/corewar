/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** helpers for instruction tests
*/

#ifndef INSTRUCTIONS_TEST_UTILS_H_
    #define INSTRUCTIONS_TEST_UTILS_H_

    #include <stdlib.h>
    #include <string.h>
    #include "define.h"
    #include "struct.h"
    #include "utils.h"

static inline void fill_u32(unsigned char *buffer, unsigned int value)
{
    for (unsigned int i = 0; i < REG_SIZE; i++){
        buffer[REG_SIZE - 1 - i] = (unsigned char)(value & 0xFF);
        value >>= 8;
    }
}

static inline unsigned int read_u32(const unsigned char *buffer)
{
    unsigned int value = 0;

    for (unsigned int i = 0; i < REG_SIZE; i++)
        value = (value << 8) | buffer[i];
    return value;
}

static inline arg_t make_arg(char type, unsigned int size,
    unsigned char *buffer)
{
    arg_t arg = {.type = type, .size = size, .arg = buffer};
    return arg;
}

static inline void destroy_game_infos(robot_game_infos_t *infos)
{
    if (!infos)
        return;
    if (infos->regs){
        for (unsigned int i = 0; i < REG_NUMBER; i++)
            free(infos->regs[i]);
        free(infos->regs);
    }
    free(infos);
}

static inline void destroy_robot(robot_infos_t *robot)
{
    if (!robot)
        return;
    if (robot->child){
        destroy_robot(robot->child);
        free(robot->child);
        robot->child = NULL;
    }
    destroy_game_infos(robot->game_infos);
    robot->game_infos = NULL;
}

static inline void destroy_test_main(main_t *main)
{
    if (!main)
        return;
    if (main->robots){
        for (unsigned int i = 0; i < main->nbr_robots; i++)
            destroy_robot(&main->robots[i]);
        free(main->robots);
    }
    free(main->arena);
    free(main);
}

static inline main_t *create_test_main(unsigned int id, const char *name)
{
    main_t *main = calloc(1, sizeof(main_t));

    if (!main)
        return NULL;
    main->arena = calloc(MEM_SIZE, sizeof(unsigned char));
    main->robots = calloc(1, sizeof(robot_infos_t));
    main->nbr_robots = 1;
    if (!main->arena || !main->robots){
        destroy_test_main(main);
        return NULL;
    }
    main->robots[0].id = id;
    main->robots[0].live = false;
    main->robots[0].child = NULL;
    main->robots[0].parent = NULL;
    main->robots[0].game_infos = calloc(1, sizeof(robot_game_infos_t));
    if (!main->robots[0].game_infos){
        destroy_test_main(main);
        return NULL;
    }
    main->robots[0].game_infos->regs = calloc(REG_NUMBER,
        sizeof(unsigned char *));
    if (!main->robots[0].game_infos->regs){
        destroy_test_main(main);
        return NULL;
    }
    for (unsigned int i = 0; i < REG_NUMBER; i++){
        main->robots[0].game_infos->regs[i] = calloc(REG_SIZE,
            sizeof(unsigned char));
        if (!main->robots[0].game_infos->regs[i]){
            destroy_test_main(main);
            return NULL;
        }
    }
    my_strcpy(main->robots[0].header.prog_name, name);
    return main;
}

static inline void set_register_value(main_t *main, unsigned int robot_id,
    unsigned int reg_id, unsigned int value)
{
    fill_u32(main->robots[robot_id].game_infos->regs[reg_id], value);
}

static inline void set_arena_value(main_t *main, unsigned int pos,
    unsigned int value)
{
    unsigned char buffer[REG_SIZE] = {0};

    fill_u32(buffer, value);
    for (unsigned int i = 0; i < REG_SIZE; i++)
        main->arena[(pos + i) % MEM_SIZE] = buffer[i];
}

#endif