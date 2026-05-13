##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = 	src/fill_instr/check_instr.c 			\
		src/fill_instr/fill_robot_instr.c 		\
		src/game_loop/get_size_from_id.c	\
		src/game_loop/translate_mem.c		\
		src/game_loop/apply_instr.c			\
		src/game_loop/game_loop.c			\
		src/compute/bin_and.c	\
		src/compute/bin_or.c	\
		src/compute/bin_xor.c	\
		src/compute/hexa_diff.c	\
		src/compute/hexa_sum.c	\
		src/init/init_arg.c		\
		src/init/init_instr.c	\
		src/init/init_main.c	\
		src/instructions/basic_instr.c		\
		src/instructions/bin_instr.c		\
		src/instructions/fork_instr.c		\
		src/instructions/load_instr.c		\
		src/instructions/store_instr.c		\
		src/parsing_args/alloc_args.c			\
		src/parsing_args/manage_flag.c			\
		src/parsing_args/parse_args.c			\
		src/utils/conversions.c			\
		src/utils/my_intlen.c			\
		src/utils/my_put_nbr.c			\
		src/utils/my_putchar.c			\
		src/utils/my_strcmp.c 			\
		src/utils/put_error.c 			\
		src/utils/my_getnbr.c 			\
		src/utils/my_strlen.c 			\
		src/utils/my_strdup.c 			\
		src/utils/my_ustrcat.c 			\
		src/utils/my_ustrndup.c			\
		src/utils/is_nbr.c 				\
		src/utils/uctoui.c				\
		src/utils/uctohex.c				\
		src/utils/set_carry_null_reg.c	\
		src/utils/free_values.c			\
		src/utils/get_type_size.c		\
		src/utils/hextouc.c				\
		src/utils/cp_robot.c			\
		src/free_all.c 			\
		src/main_functions.c 	\
		src/dump_flag.c			\
		src/op.c

TEST =	tests/utils_tests/conversion_tests.c		\
		tests/utils_tests/get_type_size_tests.c		\
		tests/utils_tests/hextouc_tests.c			\
		tests/utils_tests/is_nbr_tests.c			\
		tests/utils_tests/my_getnbr_tests.c			\
		tests/utils_tests/my_strcmp_tests.c			\
		tests/utils_tests/my_strdup_tests.c			\
		tests/utils_tests/put_error_tests.c			\
		tests/main_functions_tests.c

NAME =	corewar

CC = epiclang

CFLAGS = -I./include -g

OBJ = 	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) main.c $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

fclean:	clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

tests_run:	clean
	$(CC) -o unit_tests $(SRC) $(TEST) -lcriterion --coverage $(CFLAGS)
	./unit_tests

coverage:	tests_run
	gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/
	gcovr --branches --gcov-executable "llvm-cov-20 gcov" --exclude tests/

#for mac

mac_tests_run:	clean
	gcc -o unit_tests $(SRC) tests/*.c tests/utils_tests/*.c -lcriterion --coverage $(CFLAGS)
	./unit_tests

gcovrex:	re
	$(MAKE) mac_tests_run
	gcovr --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"
	gcovr --txt-metric branch --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"

valgrind: re
	$(MAKE) clean
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=valgrind-out.txt \
         ./$(NAME) -dump 0 examples/champions/bill.cor


re_mac:
	$(MAKE) fclean
	$(MAKE) -j8 all

tester_run: $(NAME)
	python3 tester/run.py

.PHONY: all clean fclean re compile tests_run gcovrex tests_run_lib gcovrex_lib valgrind