##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

SRC = 	main.c \
		src/utils/*.c \

NAME =	project

LIB = -L./lib/my_printf -lmy_printf

CC = epiclang

INCLUDE = -I ./include

.PHONY: all clean fclean re compile tests_run gcovrex tests_run_lib gcovrex_lib valgrind

all:
	$(MAKE) -C lib/my_printf all
	$(CC) -o $(NAME) $(SRC) $(LIB) $(INCLUDE)

clean:
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests
	$(MAKE) -C lib/my_printf clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C lib/my_printf fclean

re:
	$(MAKE) fclean
	$(MAKE) all

tests_run:	clean
	$(CC) -o unit_tests $(SRC) tests/*.c -lcriterion --coverage $(LIB) $(INCLUDE)
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
	$(CC) -o $(NAME) $(SRC) $(LIB) $(INCLUDE)
	valgrind ./$(NAME)

valgrind: all
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=valgrind-out.txt \
         ./$(NAME)
