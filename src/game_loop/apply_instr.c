/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"
#include "utils.h"
#include "game.h"

bool apply_instructions(main_t *main)
{
    unsigned int size = 0;
    char *instr = NULL;
    int pos_start = 0;

    for (unsigned int i = 0; i < main->args.nbr_robots; i++){
        if (main->robots[i].cycles_remaining){
            main->robots[i].cycles_remaining--;
            continue;
        }
        pos_start = main->robots[i].pos_start;
        size = get_args_size(main->arena[pos_start]);
        instr = my_strndup((char *)main->arena, pos_start, pos_start + size);
        if (!instr)
            return put_error("Error: malloc in apply_instructions.\n", NULL);
        if (!check_function(instr))
            return false; //instruction parsing fail -> corrupted memory -> skip/exit ?
        //translate memory in args and call instruction
    }
    return true;
}
