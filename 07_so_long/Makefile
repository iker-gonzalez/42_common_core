# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 16:00:53 by ikgonzal          #+#    #+#              #
#    Updated: 2021/12/13 18:05:13 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror
SRC  = ft_free_map.c \
			 ft_check_ber.c \
			 ft_fill_p2.c \
			 ft_move_player.c \
			 ft_hook.c \
			 main.c \
			 get_next_line.c \
			 get_next_line_utils.c \
			 ft_strlen.c \
			 ft_check_errors.c \
			 ft_so_long_utils.c \
			 ft_fill_map.c

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@ echo "so_long compiled 🐒"

clean:
	@ rm -rf so_long

fclean: clean
	@rm -rf so_long
	@rm -rf so_long.dSYM
	@ echo "so_long cleaned 🧤"

re: fclean all

.PHONY : all clean fclean re

