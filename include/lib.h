/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my header
*/
#ifndef MY_LIB_H_
    #define MY_LIB_H_

    #include "struct.h"

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
char *my_strlow(char *str);
char *my_strup(char *str);
char *my_strndup(char *src, int start, int end);
char *my_revstr(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int end);
void my_sort_str(char **tab, int nb);
void swap_str(char **tab, int j);
int is_in_tab(char **tab, char *str);
int is_in_str(char *str, char letter);
int is_nbr(char chara);
int is_char(char chara);
char *my_strdup(char *src);
char *my_strcat(char *dest, char *src, char separator);
int my_printf(const char *format, ...);

int my_put_nbr(int nb);
int my_intlen(int nb);
void my_put_dbl(double dbl, int after_coma);
char get_sign_nb(int n);
double my_get_dbl(char const *str, int start);
int my_getnbr(char const *str, int start);
int get_pow(double nbr, int times);

int get_len_list(linked_list_t *list);
int add_head(linked_list_t **list, data_t *data);
int add_tail(linked_list_t **list, data_t *data);
void delete_node(linked_list_t *temp, linked_list_t **list);
void disp_list(linked_list_t *list, void (*disp_data)(data_t *));
void sort_list(linked_list_t *list, int reverse,
    void (*sort_fct)(linked_list_t *, int));
void switch_id(linked_list_t *temp, int reverse);
void switch_datas(linked_list_t *temp1, linked_list_t *temp2);

void put_error(char *str);
char *get_file(char *path);
char *append_line(char *buffer, char *line);
char *get_line(char *path, char *match);

int my_htonl(int val);
short my_htons(short val);

#endif /* !MY_LIB_H_ */
