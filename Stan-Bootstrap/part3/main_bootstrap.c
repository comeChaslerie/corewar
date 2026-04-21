/*
** EPITECH PROJECT, 2025
** Project_name
** File description:
** main_function
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");

    get_champion_infos(fp);
    get_args(104);
}
