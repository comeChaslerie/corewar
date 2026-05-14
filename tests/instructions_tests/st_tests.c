/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** tests for store_instr
*/

#include <criterion/criterion.h>
#include "instructions.h"
#include "instructions_test_utils.h"

Test(store_instr, copies_register_into_register)
{
    main_t *main = create_test_main(1, "StoreBot");
    unsigned char reg_src[1] = {1};
    unsigned char reg_dest[1] = {2};
    arg_t arg0 = make_arg(T_REG, 1, reg_src);
    arg_t arg1 = make_arg(T_REG, 1, reg_dest);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1};

    set_register_value(main, 0, 1, 0xDEADBEEF);
    cr_assert(store_instr(main, args, 0));
    cr_assert_eq(read_u32(main->robots[0].game_infos->regs[2]), 0xDEADBEEF);
    destroy_test_main(main);
}

Test(store_instr, copies_register_into_arena_with_idx_modulo)
{
    main_t *main = create_test_main(1, "StoreBot");
    unsigned char reg_src[1] = {1};
    unsigned char dest_offset[IND_SIZE] = {0};
    arg_t arg0 = make_arg(T_REG, 1, reg_src);
    arg_t arg1 = make_arg(T_IND, IND_SIZE, dest_offset);
    arg_t *args[MAX_ARGS_NUMBER] = {&arg0, &arg1};

    /* write 2-byte big-endian indirect offset */
    dest_offset[0] = (unsigned char)((20 >> 8) & 0xFF);
    dest_offset[1] = (unsigned char)(20 & 0xFF);
    main->robots[0].game_infos->pc = 10;
    set_register_value(main, 0, 1, 0x11223344);
    cr_assert(store_instr(main, args, 0));
    cr_assert_eq(read_u32(&main->arena[30]), 0x11223344);
    destroy_test_main(main);
}
