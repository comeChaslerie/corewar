/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** my_strdup tests
*/
#include <criterion/criterion.h>
#include "utils.h"


Test(my_strdup, basic_dup)
{
    char *my_dup = my_strdup("dup");

    cr_assert(strcmp(my_dup, "dup") == 0);
    free(my_dup);
}

Test(my_strdup, empty_dup)
{
    char *my_dup = my_strdup("");

    cr_assert(strcmp(my_dup, "") == 0);
    free(my_dup);
}

Test(my_strdup, null_dup)
{
    char *my_dup = my_strdup(NULL);

    cr_assert(my_dup == NULL);
    free(my_dup);
}


Test(my_strndup, basic_full_dup)
{
    char *my_dup = my_strndup("dup", 0, 3);

    cr_assert(strcmp(my_dup, "dup") == 0);
    free(my_dup);
}

Test(my_strndup, out_of_range_dup)
{
    char *my_dup = my_strndup("", 0, 2);

    cr_assert(strcmp(my_dup, "") == 0);
    free(my_dup);
}

Test(my_strndup, other_start_dup)
{
    char *my_dup = my_strndup("dup", 1, 3);

    cr_assert(strcmp(my_dup, "up") == 0);
    free(my_dup);
}

Test(my_strndup, null_dup)
{
    char *my_dup = my_strndup("NULL", 4, 0);

    cr_assert(my_dup == NULL);
    free(my_dup);
}
