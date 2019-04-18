##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Generic Makefile.
##

MAIN	=	main.c	\
		src/fct_bsq.c	\

SRC	=	src/fct_stat.c	\
		src/get_main_str.c	\
		src/get_first_line.c	\

OBJ	=	$(SRC:.c=.o)

LIB_SRC	=	lib/my_strlen.c	\
		lib/my_strdup.c	\
		lib/my_strcpy.c	\
		lib/is_numeric.c	\
		lib/my_atoi.c	\

LIB_OBJ	=	$(LIB_SRC:.c=.o)

TESTS	=	tests/test_fct_stat.c	\
		tests/test_get_main_str.c	\
		tests/test_get_first_line.c	\


EXEC	=	bsq

LIB_NAME	=	libmylib.a

CFLAGS	+=	-W -Wall -Wextra -Wshadow -std=c99 -pedantic -I./include  -Llib -lmylib

TESTS_NAME	=	unit_tests

TESTS_FLAGS	=	--coverage -lcriterion -Llib -lmylib -I./include

all:	lib $(EXEC)

$(EXEC):	$(OBJ)
	@gcc -o $(EXEC) $(MAIN) $(OBJ) $(CFLAGS)

lib:	$(LIB_OBJ)
	@ar rc lib/$(LIB_NAME) $(LIB_OBJ)

tests_run:	lib
	@gcc $(SRC) $(TESTS) -o $(TESTS_NAME) $(TESTS_FLAGS)
	@./$(TESTS_NAME)
	@mv test*.gc* tests
	##ligne coverage
	@gcovr -r . -s --exclude-directories tests
	##backslash n
	##branch coverage
	@gcovr -b . -s --exclude-directories tests

clean:
	@rm -f $(OBJ)

lib_clean:
	@rm -f $(LIB_OBJ)

tests_clean:
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f $(TESTS_NAME)

aclean:	clean lib_clean tests_clean

fclean:	clean lib_clean tests_clean
	@rm -f $(EXEC)
	@rm -f lib/$(LIB_NAME)

re:	fclean all

.PHONY:	all lib_clean tests_clean aclean fclean re
