/*
** EPITECH PROJECT, 2025
** asm
** File description:
** The main instructions
*/

#include "op.h"
#include "my.h"
#include <unistd.h>

const op_t op_tab[] = {
    {"none", 0, {0}, 0, 1, "Nothing", NULL},
    {"live", 1, {T_DIR}, 1, 10, "alive", &live_instr},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", &load_instr},
    {"st", 2, {T_REG, T_REG | T_IND}, 3, 5, "store", &store_instr},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", &add_instr},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "subtraction", &sub_instr},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 6, 6,
     "binary and (and  r1, r2, r3   r1&r2 -> r3", &bin_and_instr},
    {"or", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 7, 6,
     "binary or  (or   r1, r2, r3   r1 | r2 -> r3", &bin_or_instr},
    {"xor", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG}, 8, 6,
     "binary exclusive or (xor  r1, r2, r3   r1^r2 -> r3", &bin_xor_instr},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", &jump_instr},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 10, 25,
     "load indirect", &load_ind_instr},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR }, 11, 25,
      "store indirect", &store_ind_instr},
    {"fork", 1, {T_DIR}, 12, 800, "fork", &fork_instr},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", &load_long_instr},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG}, 14, 50,
      "long load indirect", &load_long_ind_instr},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", &fork_long_instr},
    {"print", 1, {T_REG}, 16, 2, "print character", &print_instr},
    {0, 0, {0}, 0, 0, 0}
};
