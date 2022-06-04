NAME = microshell

SRC =	microshell.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)

	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@ echo "microshell compiled ☘︎"

clean:
	@rm -rf microshell

fclean: clean
	@rm -rf microshell
	@rm -rf	microshell.dSYM
	@rm -rf .DStore
	@rm -rf *.o
	@echo "microshell cleaned🤘🏻"

re: fclean all

.PHONY : all clean fclean re