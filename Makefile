CC	=	gcc

SRC	=	$(shell find src -name '*.c')

OBJ	=	$(patsubst src/%.c,bin/%.o,$(SRC))

CFLAGS	=	-g3					\
			-W					\
			-Wall				\

LDFLAGS	=	-L.					\
			-lmy				\
			-lmyCSFML			\
			-lm					\
			-lcsfml-graphics	\
			-lcsfml-system		\
			-lcsfml-audio		\
			-lcsfml-window		\

EXEC	=	minesweeper

H_NAME	=	$(shell find include -name '*.h')

LIB_NAME	=	$(shell find . -maxdepth 1 -name '*.a')

all:	compile_lib $(EXEC)

compile_lib:
	make -C lib/my
	make -C lib/my_CSFML

$(EXEC):	$(H_NAME) $(LIB_NAME) $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

bin/%.o:	src/%.c $(H_NAME) $(LIB_NAME)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -rf bin
	make clean -C lib/my
	make clean -C lib/my_CSFML

fclean:	clean
	rm -f $(EXEC)
	make fclean -C lib/my
	make fclean -C lib/my_CSFML

re:	fclean all

.PHONY:	all compile_lib clean fclean re
