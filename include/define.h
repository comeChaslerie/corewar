/*
** EPITECH PROJECT, 2025
** asm
** File description:
** Header for the operations
*/

#ifndef DEFINE_H_
    #define DEFINE_H_

    #include <stdbool.h>

    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512 /* modulo of the index < */
    #define MAX_ARGS_NUMBER 4 /* this may not be changed 2^*IND_SIZE */

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    #define PACKED_ATTR __attribute__((packed))

    #define MAX_ROBOT_NBR 4
/*
** regs
*/
    #define REG_NUMBER 16 /* r1 <--> rx */

/*
**
*/
typedef char args_type_t;

/* register */
    #define T_REG 1
/* direct  (ld  #1,r1  put 1 into r1) */
    #define T_DIR 2
/* indirect always relative (ld 1,r1 put what's in the address (1+pc) into r1
(4 bytes )) */
    #define T_IND 4
/* LABEL */
    #define T_LAB 8

/*
** size (in bytes)
*/
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE 1

/*
** header
*/
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

/*
** live
*/
    #define CYCLE_TO_DIE 1536 /* number of cycle before beig declared dead */
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

/*
** parsing
*/
    #define SUCCESS 0

    #define FLAG_CHAR '-'
    #define DUMP_FLAG "-dump"
    #define LOAD_FLAG "-a"
    #define ID_FLAG "-n"

    #define SECURE_DIST 50

    #define NO_ROBOT -1
    #define NO_ID_ROBOT 0

    #define NOT_ID -2

    #define NO_VALUE_LOAD_POS -1

    #define NO_CYCLE_DUMP -1

/*
** dump
*/
    #define LIST_HEXA "0123456789ABCDEF"
    #define NB_HEXA 16
    #define NB_BYTE_LINE 32
    #define NEW_LINE_CHAR "\n"
    #define SPACE_CHAR " "
    #define ZERO_CHAR "0"
    #define COLON_CHAR ":"
    #define SIZE_INDEX 10
    #define SEPARATOR_MEMORY "--"
    #define SIZE_BEFORE_SEP 10
    #define OPEN_PARENTHESE "("
    #define CLOSE_PARENTHESE ")"
    #define NB_SPACE 4
    #define PC_SIZE 8

#endif /* DEFINE_H_ */
