##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile for mylib
## Makefile
##

CC	=	gcc

SRC	=	concat_2_str.c	\
		concat_str.c	\
		convert_int_to_str.c	\
		convert_str_in_int.c	\
		free_word_array.c	\
		mini_fdprintf.c	\
		mini_printf.c	\
		my_compute_power_rec.c	\
		my_fdputchar.c	\
		my_fdput_nbr.c	\
		my_fdputstr.c	\
		my_intlen.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strcmp.c	\
		my_strdup.c	\
		my_str_isnum.c	\
		my_strlen_array.c	\
		my_strlen.c	\
		my_strncmp.c	\
		my_strndup.c	\
		my_tabdup.c	\
		parse_str.c	\
		print_word_array.c	\
		sep_str.c	\
		my_abs.c	\
		my_strncpy.c

OBJ	=	$(SRC:%.c=bin/%.o)

CFLAGS	=	-g3 -W -Wall

H_NAME	=	my.h

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
	@rm -rf bin

fclean:	clean
	rm -f $(LIB_NAME) ../../$(LIB_NAME)

re:	fclean all

.PHONY:	all clean fclean re
