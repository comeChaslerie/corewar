/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** main_functions
*/
#include "struct.h"
#include "parse_args.h"
#include "handle_main.h"
#include <stdio.h>

int main_functions(int argc, char **argv)
{
    args_t *args = parse_args(argc, argv);
    main_t *main = NULL;

    if (args == NULL)
        return 84;
    main = init_main(args);
    if (main == NULL)
        return 84;
    return 0;
}
