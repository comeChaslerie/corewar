/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef INIT_MAIN_H_
    #define INIT_MAIN_H_

    #include "struct.h"

main_t *init_main(args_t *args);
void *free_main(char *str, main_t *main, args_t *args);
bool fill_robot_instr(main_t *main, robot_args_t *robot_args);

#endif /* !MY_H_ */
