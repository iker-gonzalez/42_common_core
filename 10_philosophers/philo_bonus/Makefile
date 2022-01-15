# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 16:09:39 by ikgonzal          #+#    #+#              #
#    Updated: 2022/01/13 11:55:53 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRC =	actions_bonus.c \
		main_bonus.c \
		init_philo_bonus.c \
		ft_atoi_bonus.c \
		get_time_bonus.c \
		ft_print_status_bonus.c \
		free_bonus.c \

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@ echo "philo_bonus compiled 🦧"

bonus: all

clean:
	@rm -rf philo_bonus

fclean:
	@rm -rf philo_bonus
	@rm -rf	philo_bonus.dSYM
	@rm -rf .DStore
	@echo "philo_bonus cleaned🤘🏻"

re: fclean all

.PHONY : all bonus clean fclean re
