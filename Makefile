##
## Makefile for 102cipher in /home/raphael.goulmot/rendu/102cipher
##
## Made by Raphaël Goulmot
## Login   <raphael.goulmot@epitech.net>
##
## Started on  Tue Nov 29 15:57:16 2016 Raphaël Goulmot
##

CC	=	gcc

SRC	=	src/utils/my_putstr_err.c	\
		src/utils/my_putchar.c		\
		src/utils/my_putstr.c		\
		src/utils/my_strlen.c		\
		src/utils/my_getnbr.c		\
		src/utils/my_put_nbr.c		\
		src/utils/my_is.c		\
		src/utils/my_string.c		\
		src/utils/get_next_line.c	\
		src/utils/my_rand.c		\
		src/core/debug.c		\
		src/core/usage.c		\
		src/core/shape.c		\
		src/core/tetris.c		\
		src/core/commands.c		\
		src/core/params.c		\
		src/core/graphic.c		\
		src/core/print.c		\
		src/core/menu/main_menu.c	\
		src/core/game.c			\
		src/core/controls.c		\
		src/core/menu/theme.c		\
		src/core/menu/choices.c		\
		src/core/menu/command_section.c	\
		src/core/main.c			\
		include/get_next_line.h		\
		include/usage.h			\
		include/shape.h			\
		include/tetris.h		\
		include/struct.h		\
		include/debug.h			\
		include/commands.h		\
		include/params.h		\
		include/graphic.h		\
		include/print.h			\
		include/game.h			\
		include/controls.h		\
		include/menu.h			\
		include/utils.h

OBJ	=	$(SRC:.c=.o)

TMP	=	$(OBJ:.h=.h~)

CFLAGS	=	-Wextra -Werror -Iinclude -lncurses

NAME	=	tetris

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(TMP)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

run:
	./$(NAME) -d
