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
bool fill_robot_instr(main_t *main, robot_infos_t *robot_infos,
    robot_args_t *robot_args);
bool check_id(unsigned char elem, unsigned int *size_elem,
    unsigned int *id_instr);
bool check_byte_code(unsigned char elem, unsigned int *size_elem,
    unsigned int id_instr);
bool check_args(unsigned char *elem, unsigned int *size_elem);

#endif /* !MY_H_ */
