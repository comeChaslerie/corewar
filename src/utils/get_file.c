/*
** EPITECH PROJECT, 2025
** get_file
** File description:
** get the inside of a file
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *search_match(FILE *fp, char *buffer, char *match)
{
    size_t len = 0;

    if (my_strncmp(buffer, match, my_strlen(match)) == 0)
        return buffer;
    while (getline(&buffer, &len, fp) != -1)
        if (my_strncmp(buffer, match, my_strlen(match)) == 0)
            break;
    return buffer;
}

char *get_line(char *path, char *match)
{
    char *buffer = NULL;
    FILE *fp;
    size_t len = 0;

    if (path == NULL)
        return NULL;
    fp = fopen(path, "r");
    if (fp == NULL || getline(&buffer, &len, fp) == -1) {
        free(buffer);
        if (fp != NULL)
            fclose(fp);
        return NULL;
    }
    buffer = search_match(fp, buffer, (match == NULL) ? "" : match);
    fclose(fp);
    return buffer;
}

char *append_line(char *buffer, char *line)
{
    char *new_buf;

    if (buffer == NULL)
        return my_strdup(line);
    new_buf = my_strcat(buffer, line, '\0');
    free(buffer);
    return new_buf;
}

char *get_file(char *path)
{
    char *buffer = NULL;
    char *line = NULL;
    FILE *fp;
    size_t len = 0;

    if (path == NULL)
        return NULL;
    fp = fopen(path, "r");
    if (fp == NULL)
        return NULL;
    while (getline(&line, &len, fp) != -1)
        buffer = append_line(buffer, line);
    free(line);
    fclose(fp);
    return buffer;
}
