##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = 	src/instructions/basic_instr.c		\
		src/instructions/bin_instr.c		\
		src/instructions/fork_instr.c		\
		src/instructions/load_instr.c		\
		src/instructions/store_instr.c		\
		src/linked_lists/add_to_list.c	\
		src/linked_lists/delete_node.c	\
		src/linked_lists/destroy_list.c	\
		src/linked_lists/disp_list.c	\
		src/linked_lists/get_len_list.c \
		src/parsing_args/alloc_args.c 		\
		src/parsing_args/manage_flag.c 		\
		src/parsing_args/parse_args.c 		\
		src/utils/my_strcmp.c 		\
		src/utils/put_error.c 		\
		src/utils/my_getnbr.c 		\
		src/utils/my_strlen.c 		\
		src/utils/my_strdup.c 		\
		src/utils/is_nbr.c 			\
		src/init_main.c			\
		src/main_functions.c 	\
		src/op.c				\
		

NAME =	corewar

CC = epiclang

INCLUDE = -I ./include

.PHONY: all clean fclean re compile tests_run gcovrex tests_run_lib gcovrex_lib valgrind

all:
	$(CC) -o $(NAME) main.c $(SRC) $(INCLUDE)

clean:
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

fclean:	clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

tests_run:	clean
	$(CC) -o unit_tests $(SRC) tests/*.c -lcriterion --coverage $(INCLUDE)
	./unit_tests

coverage:	tests_run
	gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/
	gcovr --branches --gcov-executable "llvm-cov-20 gcov" --exclude tests/

tests_run_lib:	clean
	gcc -o unit_tests --coverage -lcriterion \
		./tests_lib/*.c \
		./src/utils/*.c \
		./lib/my_printf/*.c \
		./lib/my_printf/arguments/*.c \
		./lib/my_printf/flags/*.c \
		./lib/my_printf/lib/*.c \
		-I./include

gcovrex_lib:	clean
	$(MAKE) tests_run_lib
	./unit_tests
	gcovr --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*" --exclude "tests_lib/.*"
	gcovr --txt-metric branch --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*" --exclude "tests_lib/.*"

compile:
	rm -f $(NAME)
	$(CC) -o $(NAME) $(SRC) $(INCLUDE)
	valgrind ./$(NAME)

valgrind: all
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=valgrind-out.txt \
         ./$(NAME)

re_mac:
	$(MAKE) fclean
	$(MAKE) -j8 all
