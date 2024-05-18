##
## EPITECH PROJECT, 2023
## GAME-JAM
## File description:
## Makefile
##

MAIN	=	brasier_en_duel.c

BIN_NAME	=	brasier_en_duel

LIBMY_NAME	=	libmy.a

CC	=	gcc

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

FLAG	=	-Wextra -Wall

LIB_PATH	=	-L.

LIBMY	=	-lmy

MY_H	=	-I./include

all:
	cd ./lib/my && make
	make compile

compile:	$(MAIN)
	$(CC) $(FLAG) -o $(BIN_NAME) $(MAIN) $(LIB_PATH) $(LIBMY) $(MY_H) $(CSFML)

lib:
	cd ./lib/my && make

libre:
	cd ./lib/my && make re

libfclean:
	cd ./lib/my && make fclean

fclean:	libfclean
	rm -f $(BIN_NAME)
	rm -f *.c~

clean:	libfclean
	rm -f *.c~

re:	fclean all
