##
## EPITECH PROJECT, 2019
## navy
## File description:
## Makefile
##

SRC	=	map.c \
		win.c \
		main.c \
		navy.c \
		ship.c \
		usage.c \
		array.c \
		client.c \
		server.c \
		attack.c \
		sigdone.c \
		attacked.c
OBJ	=	$(foreach source, $(SRC), obj/$(source:.c=.o))
LIB	=	src/lib/libmy.a
NAME	=	navy
CFLAGS	=	-Wall -Wextra -Wno-unused-parameter -g3 -Isrc/include
LDFLAGS	=	-Lsrc/lib -lmy

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -o $@ $(OBJ) $(LDFLAGS)

obj/%.o: src/%.c
	gcc -c $< -o $@ $(CFLAGS)

$(LIB):
	make -C src/lib/my

clean:
	rm -f $(OBJ)
	make -C src/lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C src/lib/my fclean

re: fclean all
