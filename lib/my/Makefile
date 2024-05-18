##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	= 	main_menu.c					\
		fonction_disp.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

COPY_STRUCT_H	=	cp ./structures.h ../../include

COPY_MY_H	=	cp ./my.h ../../include

COPY_LIBMY_A	=	cp ./libmy.a ../../.

LIBMY_A	=	./libmy.a

STRUCT_H	=	../../include/structures.h

MY_H	=	./../../include/my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	$(COPY_STRUCT_H)
	$(COPY_MY_H)
	$(COPY_LIBMY_A)

clean:
	rm -f $(OBJ)
	rm -f $(LIBMY_A)
	rm -f $(MY_H)
	rm -f $(STRUCT_H)

fclean: clean
	rm -f $(NAME)
	rm -f ../../libmy.a

re:	fclean	all

.PHONY: all clean fclean re
