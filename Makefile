CC	=	gcc

SRC	=	$(shell find src -name '*.c')

OBJ	=	$(patsubst src/%.c,bin/%.o,$(SRC))

CFLAGS	=	-g3					\
			-W					\
			-Wall				\

LDFLAGS	=	-L.					\
			-lmy				\
			-lm					\
			-lcsfml-graphics	\
			-lcsfml-system		\
			-lcsfml-audio		\
			-lcsfml-window		\

EXEC	=	minesweeper

H_NAME	=	$(shell find include -name '*.h')

LIB_NAME	=	libmy.a

all:	compile_lib $(EXEC)

compile_lib:
	make -C lib/my

$(EXEC):	$(H_NAME) $(LIB_NAME) $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

bin/%.o:	src/%.c $(H_NAME) $(LIB_NAME)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -rf bin
	make clean -C lib/my

fclean:	clean
	rm -f $(EXEC)
	make fclean -C lib/my

re:	fclean all

.PHONY:	all compile_lib clean fclean re
