/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/

#ifndef UTILS_H_
    #define UTILS_H_

void *put_error(const char *str, void *return_value);
int my_strncmp(char *s1, char *s2, int end);
int my_strcmp(char *s1, char *s2);
int my_getnbr(char const *str, int start);
int my_strlen(const char *str);
char *my_strdup(char *src);
bool is_nbr(char *str);

#endif
