##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile for mylib
## Makefile
##

CC	=	gcc

SRC	=	$(shell find . -name '*.c')

OBJ	=	$(SRC:%.c=bin/%.o)

CFLAGS	=	-g3 -W -Wall

H_NAME	=	$(shell find . -name '*.h')

LIB_NAME	=	libmy.a

all:	$(LIB_NAME)

$(LIB_NAME):	$(H_NAME) $(OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	cp $(LIB_NAME) ../..
	cp $(H_NAME) ../../include

bin/%.o:	%.c $(H_NAME)
	@mkdir -p bin
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -rf bin

fclean:	clean
	rm -f $(LIB_NAME) ../../$(LIB_NAME)

re:	fclean all

.PHONY:	all clean fclean re
