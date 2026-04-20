##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = 	src/utils/get_file.c \
		src/utils/is_in.c	\
		src/utils/is_something.c	\
		src/utils/linked_list.c	\
		src/utils/linked_list2.c	\
		src/utils/my_get_dbl.c	\
		src/utils/my_getnbr.c	\
		src/utils/my_htonls.c	\
		src/utils/my_intlen.c	\
		src/utils/my_put_dbl.c	\
		src/utils/my_put_nbr.c	\
		src/utils/my_putchar.c	\
		src/utils/my_putstr.c	\
		src/utils/my_revstr.c	\
		src/utils/my_sort_str.c	\
		src/utils/my_strcat.c	\
		src/utils/my_strcmp.c	\
		src/utils/my_strdup.c	\
		src/utils/my_strlen.c	\
		src/utils/put_error.c	\
		src/utils/strlow_strup.c

NAME =	project

LIB =

CC = epiclang

INCLUDE = -I ./include

.PHONY: all clean fclean re compile tests_run gcovrex tests_run_lib gcovrex_lib valgrind

all:
	$(CC) -o $(NAME) bs_come/read_bin.c $(SRC) $(LIB) $(INCLUDE)

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
