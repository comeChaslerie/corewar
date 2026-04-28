/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Parse all the args
*/
#include <stdbool.h>
#include <stdio.h>
#include "op.h"
#include "struct.h"
#include "utils.h"
#include "handle_main.h"

int my_htonl(int val)
{
    int result = 0;

    result = (val >> 24) & 0xFF;
    result += (val >> 8) & 0xFF00;
    result += (val << 8) & 0xFF0000;
    result += (val << 24) & 0xFF000000;
    return result;
}

static void add_to_arena(unsigned char *arena, unsigned char *buffer,
    unsigned int size_buffer)
{
    for (unsigned int index = 0; index < size_buffer; index++) {
        arena[index] = buffer[index];
    }
}

unsigned char *check_instr(unsigned char *elem, unsigned int *size_buffer, FILE *fp)
{
    unsigned char *buffer = NULL;
    unsigned int size_elem = 0;

    buffer = my_ustrcat(buffer, size_buffer, elem, 1);
    if (!check_id(elem, &size_elem))
        return put_error("Bad id.", NULL);
    if (size_elem == 1) {
        fread(elem, sizeof(unsigned char), 1, fp);
        buffer = my_ustrcat(buffer, size_buffer, elem, size_elem);
        if (!check_byte_code(elem, &size_elem))
            return put_error("Bad byte code.", NULL);
    }
    fread(elem, sizeof(unsigned char), size_elem, fp);
    buffer = my_ustrcat(buffer, size_buffer, elem, size_elem);
    if (!check_args(elem, &size_elem))
        return put_error("Bad args.", NULL);
    return buffer;
}

bool get_instructions(main_t *main, robot_infos_t *robot_infos, FILE *fp)
{
    unsigned char *elem;
    unsigned char *buffer = NULL;
    unsigned int size_buffer = 0;
    unsigned int size_total = 0;
    unsigned int pos = robot_infos->pos_infos->pos_start;

    while (fread(elem, sizeof(unsigned char), 1, fp) != -1) {
        buffer = check_instr(elem, &size_buffer, fp);
        if (buffer == NULL)
            return false;
        if (pos + size_total + size_buffer > MEM_SIZE / 2)
            return false;
        add_to_arena(&main->arena[pos + size_total], buffer, size_buffer);
        size_total += size_buffer;
    }
    robot_infos->pos_infos->pos_end =
        robot_infos->pos_infos->pos_start + size_total;
    return true;
}

bool fill_robot_instr(main_t *main, robot_infos_t *robot_infos,
    robot_args_t *robot_args)
{
    FILE *fp = fopen(robot_args->filepath, "r");

    if (fp == NULL)
        return false;
    fread(&robot_infos->header, sizeof(header_t), 1, fp);
    if (my_htonl(robot_infos->header.magic) != COREWAR_EXEC_MAGIC)
        return false;
    if (!get_instructions(main, robot_infos, fp))
        return false;
    fclose(fp);
    return true;
}
