/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** put_error tests
*/
#include <criterion/criterion.h>
#include "utils.h"


Test(put_error, false_return)
{
    cr_assert(put_error("error", false) == false);
}

Test(put_error, null_return)
{
    cr_assert(put_error("error", NULL) == NULL);
}
