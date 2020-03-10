##
## EPITECH PROJECT, 2019
## my_hunter
## File description:
## Makefile
##

CFLAGS = -W -Wall -Wextra -g3 -lncurses -I./include

C_LIB = -I./include -L./lib/my -lmy

SRC = my_sokoban.c	\
	mouvement.c	\
	check_win.c	\
	collision.c	\

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

all	: $(NAME)

$(NAME)	:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(C_LIB)

clean	:
	rm -f $(OBJ)
	make clean -C lib/my

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all