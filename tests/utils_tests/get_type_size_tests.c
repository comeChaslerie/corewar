/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

#include <criterion/criterion.h>
#include "utils.h"
#include "define.h"

Test(get_type_size, basic_nbr)
{
    cr_assert(get_type_size(T_REG) == 4);
}

Test(get_type_size, t_reg_returns_reg_size)
{
    cr_assert_eq(get_type_size(T_REG), REG_SIZE);
}

Test(get_type_size, t_dir_returns_dir_size)
{
    cr_assert_eq(get_type_size(T_DIR), DIR_SIZE);
}

Test(get_type_size, t_ind_returns_ind_size)
{
    cr_assert_eq(get_type_size(T_IND), IND_SIZE);
}

Test(get_type_size, t_dir_is_four)
{
    cr_assert_eq(get_type_size(T_DIR), 4);
}

Test(get_type_size, t_ind_is_two)
{
    cr_assert_eq(get_type_size(T_IND), 2);
}

Test(get_type_size, t_lab_not_handled)
{
    cr_assert_eq(get_type_size(T_LAB), 0);
}

Test(get_type_size, zero_type)
{
    cr_assert_eq(get_type_size(0), 0);
}

Test(get_type_size, negative_type)
{
    cr_assert_eq(get_type_size(-1), 0);
}

Test(get_type_size, large_negative)
{
    cr_assert_eq(get_type_size(-9999), 0);
}

Test(get_type_size, unused_value_three)
{
    cr_assert_eq(get_type_size(3), 0);
}

Test(get_type_size, unused_value_five)
{
    cr_assert_eq(get_type_size(5), 0);
}

Test(get_type_size, unused_value_six)
{
    cr_assert_eq(get_type_size(6), 0);
}

Test(get_type_size, unused_value_seven)
{
    cr_assert_eq(get_type_size(7), 0);
}

Test(get_type_size, large_value)
{
    cr_assert_eq(get_type_size(1000000), 0);
}

Test(get_type_size, int_max)
{
    cr_assert_eq(get_type_size(2147483647), 0);
}

Test(get_type_size, combined_flags_not_matched)
{
    cr_assert_eq(get_type_size(T_REG | T_DIR), 0);
}
