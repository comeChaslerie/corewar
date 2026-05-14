/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Compute optimal default load positions for robots
*/

#include "parse_args.h"
#include "define.h"
#include "struct.h"

static unsigned int get_robots_to_place(robot_args_t *robots_args,
    unsigned int nbr_robots)
{
    unsigned int to_place = 0;

    for (unsigned int index_tab = 0; index_tab < nbr_robots; index_tab++)
        if (robots_args[index_tab].load_pos == NO_VALUE_LOAD_POS)
            to_place += 1;
    return to_place;
}

static unsigned int get_dist_from_id(unsigned int actual_pos,
    unsigned int robot_pos)
{
    int diff = actual_pos - robot_pos;

    if (diff < 0)
        diff *= -1;
    if (diff > MEM_SIZE / 2)
        return MEM_SIZE - diff;
    return diff;
}

static unsigned int get_min_dist(int actual_pos, robot_args_t *robots_args,
    unsigned int nbr_robots)
{
    unsigned int min_dist = MEM_SIZE;
    unsigned int dist = 0;

    for (unsigned int index_tab = 0; index_tab < nbr_robots; index_tab++) {
        if (robots_args[index_tab].load_pos == NO_VALUE_LOAD_POS)
            continue;
        dist = get_dist_from_id(actual_pos, robots_args[index_tab].load_pos);
        if (dist < min_dist)
            min_dist = dist;
    }
    return min_dist;
}

static int find_best_pos(robot_args_t *robots_args, unsigned int nbr_robots)
{
    unsigned int best_pos = 0;
    unsigned int best_dist = 0;
    unsigned int dist = 0;

    for (unsigned int actual_pos = 0; actual_pos < MEM_SIZE; actual_pos++) {
        dist = get_min_dist(actual_pos, robots_args, nbr_robots);
        if (dist > best_dist) {
            best_dist = dist;
            best_pos = actual_pos;
        }
    }
    return best_pos;
}

static unsigned int find_next_id(robot_args_t *robots_args,
    unsigned int nbr_robots)
{
    int smallest_index = -1;

    for (unsigned int index_tab = 0; index_tab < nbr_robots; index_tab++) {
        if (robots_args[index_tab].load_pos != NO_VALUE_LOAD_POS)
            continue;
        if (smallest_index == -1
            || robots_args[index_tab].id < robots_args[smallest_index].id)
            smallest_index = (int)index_tab;
    }
    return (unsigned)smallest_index;
}

void update_load_pos(robot_args_t *robots_args, unsigned int nbr_robots)
{
    unsigned int to_place = get_robots_to_place(robots_args, nbr_robots);
    unsigned int next_index = 0;

    while (to_place > 0) {
        next_index = find_next_id(robots_args, nbr_robots);
        robots_args[next_index].load_pos = find_best_pos(robots_args,
            nbr_robots);
        to_place -= 1;
    }
}
