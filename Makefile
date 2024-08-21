CC	=	gcc

SRC	=	src/main.c				\
		src/functions.c			\
		src/map_manager.c		\
		src/map_setter.c		\
		src/window.c			\
		src/events.c			\
		src/start_screen.c		\
		src/cursor.c			\
		src/animations.c		\
		src/sounds.c			\
		src/musics.c			\
		src/credits.c			\
		src/game.c				\

OBJ	=	$(SRC:src/%.c=bin/%.o)

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

H_NAME	=	include/my.h		\
			include/minesweeper.h	\

LIB_NAME	=	libmy.a

all:	compile_lib $(EXEC)

compile_lib:
	make -C lib/my

$(EXEC):	$(H_NAME) $(LIB_NAME) $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

bin/%.o:	src/%.c $(H_NAME) $(LIB_NAME)
	@mkdir -p bin
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)
	@rm -rf bin
	make clean -C lib/my

fclean:	clean
	rm -f $(EXEC)
	make fclean -C lib/my

re:	fclean all

.PHONY:	all compile_lib clean fclean re
