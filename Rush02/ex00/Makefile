NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	srcs/ft_get_next_line.c	\
	srcs/ft_lib.c		\
	srcs/ft_lib2.c		\
	srcs/ft_lib3.c		\
	srcs/ft_lib4.c		\
	main.c			\
	rush-01.c		\
	rush-02.c		\
	rush-03.c		\
	rush-04.c		\
	rush-05.c		\
	rush-06.c		\
	rush-07_en.c		\
	rush-08_en.c

OBJ = $(SRC:.c=.o)

RESET			= "\033[0m"
GREEN			= "\033[92m"	# Green
RED			= "\033[91m"	# Red

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready ---"$(RESET)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

rf: re
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

h:
	head -n 18 main.c

.PHONY: all clean fclean re rf
