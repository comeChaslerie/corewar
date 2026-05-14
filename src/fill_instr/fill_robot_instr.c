/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** Parse all the args
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "define.h"
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

unsigned char *add_to_arena(unsigned char *arena, unsigned char *buffer,
    unsigned int size_buffer, unsigned int pos)
{
    unsigned int index_arena = pos;

    if (buffer == NULL)
        return NULL;
    for (unsigned int index = 0; index < size_buffer; index++) {
        arena[index_arena] = buffer[index];
        index_arena = (index_arena + 1) % MEM_SIZE;
    }
    free(buffer);
    buffer = NULL;
    return buffer;
}

unsigned char *check_instr(unsigned char instr, unsigned int *size_buffer,
    FILE *fp, unsigned char *buffer)
{
    unsigned char *elem = NULL;
    unsigned int size_elem = 0;
    unsigned int id_instr = 0;

    buffer = my_ustrcat(buffer, size_buffer, &instr, 1);
    if (!check_id(instr, &size_elem, &id_instr))
        return put_error("Bad id.", NULL);
    if (size_elem == 1) {
        fread(&instr, sizeof(unsigned char), 1, fp);
        buffer = my_ustrcat(buffer, size_buffer, &instr, size_elem);
        if (!check_byte_code(instr, &size_elem, id_instr))
            return put_error("Bad byte code.", NULL);
    }
    elem = malloc(sizeof(unsigned char) * size_elem);
    fread(elem, sizeof(unsigned char), size_elem, fp);
    buffer = my_ustrcat(buffer, size_buffer, elem, size_elem);
    if (!check_args(elem, &size_elem))
        return put_error("Bad args.", NULL);
    free(elem);
    return buffer;
}

bool get_instructions(main_t *main, robot_infos_t *robot_infos, FILE *fp)
{
    unsigned char elem = '\0';
    unsigned char *buffer = NULL;
    unsigned int size_buffer = 0;
    unsigned int size_total = 0;
    unsigned int pos = robot_infos->game_infos->pc;

    while (fread(&elem, sizeof(unsigned char), 1, fp) != 0) {
        buffer = check_instr(elem, &size_buffer, fp, buffer);
        if (buffer == NULL)
            return put_error("Buffer equals null.", false);
        buffer = add_to_arena(main->arena, buffer, size_buffer,
            ((pos + size_total) % MEM_SIZE));
        size_total += size_buffer;
        size_buffer = 0;
    }
    return true;
}

bool fill_robot_instr(main_t *main, robot_infos_t *robot_infos,
    robot_args_t *robot_args)
{
    FILE *fp = fopen(robot_args->filepath, "r");

    if (fp == NULL)
        return put_error("File open failed.", false);
    if (fread(&robot_infos->header, sizeof(header_t), 1, fp) == 0)
        return put_error("The header isn't in the right format.", false);
    if (my_htonl(robot_infos->header.magic) != COREWAR_EXEC_MAGIC)
        return put_error("Bad magic number.", false);
    if (!get_instructions(main, robot_infos, fp))
        return put_error("Get instr failed.", false);
    fclose(fp);
    return true;
}
