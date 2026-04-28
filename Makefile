##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = 	src/fill_instr/check_instr.c 				\
		src/fill_instr/fill_robot_instr.c 			\
		src/instructions/basic_instr.c			\
		src/instructions/bin_instr.c			\
		src/instructions/fork_instr.c			\
		src/instructions/load_instr.c			\
		src/instructions/store_instr.c			\
		src/linked_lists/add_to_list.c		\
		src/linked_lists/delete_node.c		\
		src/linked_lists/destroy_list.c		\
		src/linked_lists/disp_list.c		\
		src/linked_lists/get_len_list.c 	\
		src/parsing_args/alloc_args.c 	\
		src/parsing_args/manage_flag.c 	\
		src/parsing_args/parse_args.c 	\
		src/utils/conversions.c 	\
		src/utils/my_strcmp.c 		\
		src/utils/put_error.c 		\
		src/utils/my_getnbr.c 		\
		src/utils/my_strlen.c 		\
		src/utils/my_strdup.c 		\
		src/utils/my_ustrcat.c 		\
		src/utils/is_nbr.c 			\
		src/free_all.c 			\
		src/init_main.c			\
		src/main_functions.c 	\
		src/op.c				\
		

NAME =	corewar

CC = epiclang

CFLAGS = -I./include

OBJ = 	$(SRC:.c=.o)

.PHONY: all clean fclean re compile tests_run gcovrex tests_run_lib gcovrex_lib valgrind


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
	$(CC) -o unit_tests $(SRC) tests/*.c -lcriterion --coverage $(CFLAGS)
	./unit_tests

coverage:	tests_run
	gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/
	gcovr --branches --gcov-executable "llvm-cov-20 gcov" --exclude tests/

#for mac

mac_tests_run:	clean
	gcc -o unit_tests $(SRC) tests/*.c -lcriterion --coverage $(CFLAGS)
	./unit_tests

gcovrex:	re
	$(MAKE) mac_tests_run
	gcovr --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"
	gcovr --txt-metric branch --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"

valgrind: all
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=valgrind-out.txt \
         ./$(NAME)

re_mac:
	$(MAKE) fclean
	$(MAKE) -j8 all
