# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 16:09:39 by ikgonzal          #+#    #+#              #
#    Updated: 2022/01/10 13:58:35 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	actions.c \
		main.c \
		init_philo.c \
		ft_atoi.c \
		get_time.c \
		ft_print_status.c \
		free.c \

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@ echo "philo compiled 🦧"

clean:
	@rm -rf philo

fclean:
	@rm -rf philo
	@rm -rf	philo.dSYM
	@rm -rf .DStore
	@echo "philo cleaned🤘🏻"

re: fclean all

.PHONY : all clean fclean re