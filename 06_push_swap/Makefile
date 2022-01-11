# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 13:12:50 by ikgonzal          #+#    #+#              #
#    Updated: 2021/11/24 11:12:22 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SANITIZE = -g3 -fsanitize=address
NAME = push_swap
SRC_FILES = ft_free.c ft_push_b_a.c ft_rb_rrb_mov.c ft_ra_rra_mov.c ft_reverse_list.c push_swap.c push_swap_errors.c ft_distribution.c push_swap_utils.c push_swap_utils2.c ft_caseof3.c ft_caseof4.c ft_caseof5.c push_swap_moves1.c push_swap_moves2.c push_swap_moves3.c ft_part.c ft_push_a_b.c
LIB = Libft/libft.a
all : $(NAME)

$(NAME) : $(SRC_FILES)
	$(MAKE) -C ./Libft
	$(MAKE) -C ./Libft bonus
	$(CC) $(SRC_FILES) $(CFLAGS) $(LIB) -o $(NAME)

clean :
	@make -C libft clean

fclean : clean
	rm -f $(NAME)
	rm -rf libft.a
	rm -rf push_swap.dSYM
	@make -C libft clean

re : fclean all

.PHONY: all clean fclean re
