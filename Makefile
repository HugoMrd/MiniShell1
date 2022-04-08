##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CC	=	gcc

SRCM	=	sources/main.c

SRC	=	sources/mini.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

RM	=	rm

CPPFLAGS =	-Wextra -Wall

CFLAGS	=	-g3

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(SRC) $(SRCM) $(CFLAGS) -L./lib/my -lmy
clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda
	make fclean -C lib/my

tests_run:
	make -C lib/my/
	gcc $(SRC) tests/test_calc.c --coverage -lcriterion $(LDFLAG)
	./a.out

re:	fclean all

.PHONY: re fclean clean all
