/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for print_instr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(print_instr, returns_true_for_valid_register, .init = cr_redirect_stdout)
{
    main_t *main = create_test_main(1, "PrintBot");
    unsigned char reg_index[1] = {1};
    arg_t arg0 = make_arg(T_REG, 1, reg_index);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0};

    cr_assert(print_instr(main, args, 0));
    destroy_test_main(main);
}
