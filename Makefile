##
## EPITECH PROJECT, 2023
## $MAKEFILE
## File description:
## Makefile for my_radar
##

INCLUDE	=	-I./include/

SRC	=	radar/main.c	\
		radar/information.c	\
		radar/init.c	\
		radar/set_objects.c	\
		radar/window.c	\
		src/my_strlen.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		radar/file.c	\
		radar/file_info.c	\
		radar/parse.c	\
		radar/set_clock.c	\
		radar/timer.c	\
		radar/calculate.c	\
		radar/set_hitbox.c	\
		radar/check_event.c	\
		radar/collision.c	\

CFLAGS	+=	-g -W

NAME	=	my_radar

OBJ 	= 	$(SRC:.c=.o)

CSFML	=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lm

all:	$(OBJ)
	gcc -o $(NAME) $(INCLUDE) $(SRC) $(CFLAGS) $(CSFML)

clean:
	rm -f $(OBJ)
	rm -f *.out
	rm -f *.log
	rm -f *.gcda
	rm -rf *.gcno
	rm -f vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all
