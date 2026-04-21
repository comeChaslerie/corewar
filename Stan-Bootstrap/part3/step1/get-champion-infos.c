/*
** EPITECH PROJECT, 2025
** Project_name
** File description:
** main_function
*/

#include "op.h"
#include "lib.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_champion_infos(FILE *fp)
{
    header_t header;

    fread(&header, sizeof(header_t), 1, fp);
    printf("prog_name: %s\n", header.prog_name);
    printf("prog_size: %i\n", my_htonl(header.prog_size));
    printf("comment: %s\n", header.comment);
    check_magic_champions(&header);
    return 0;
}
