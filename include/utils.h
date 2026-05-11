/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <stdbool.h>
    #include "struct.h"

void *put_error(const char *str, void *return_value);
int my_strncmp(char *s1, char *s2, int end);
int my_strcmp(char *s1, char *s2);
int my_getnbr(char const *str, int start);
int my_strlen(const char *str);
char *my_strdup(char *src);
char *my_strndup(char *src, int start, int end);
bool is_nbr(char *str);
unsigned char *my_ustrndup(unsigned char *src, unsigned int start,
    unsigned int end);
unsigned char *my_ustrcat(unsigned char *dest, unsigned int *size_dest,
    unsigned char *src, unsigned int size_src);
char *to_bin(unsigned char value);
unsigned int get_type_size(int type);
void free_values(void **values, unsigned int nb_values);
void set_carry_null_reg(unsigned char *reg,
    robot_game_infos_t *game_infos);
int my_intlen(int nb);
int my_intlen_u(unsigned int nb);
int my_put_nbr_u(unsigned int n);
void my_putchar(char c);
void add_to_arena(unsigned char *arena, unsigned char *buffer,
    unsigned int size_buffer);
bool cp_robot(robot_infos_t *robot);

#endif
