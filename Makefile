##
## EPITECH PROJECT, 2026
## Git-Introduction-Repository-Testing
## File description:
## Makefile
##

NAME = my_game

SRC = src/main.c \
      src/game.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Iinclude

LDFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
