NAME = rush-00

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c rush-00.c rush-01.c rush-02.c rush-03.c rush-04.c ft_lib.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

h:
	head -n 17 main.c

.PHONY: all clean fclean re
