# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 19:07:43 by adel-por          #+#    #+#              #
#    Updated: 2021/12/01 11:58:31 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = client server

BONUS = client_bonus server_bonus

SRCS_LIBFT = ft_atoi.c \
			 ft_printf.c \
			 ft_printf_utils.c \

SRCS_CLIENT =  client.c \

SRCS_CLIENT_BONUS = client_bonus.c \

SRCS_SERVER = server.c \

SRCS_SERVER_BONUS = server_bonus.c \

FLAGS = -Wall -Wextra -Werror \



$(NAME):
	@ gcc $(FLAGS) $(SRCS_LIBFT) $(SRCS_CLIENT) -o client
	@ echo "\033[38;2;243;134;48mClient compiled\033[0m 🐙"
	@ gcc $(FLAGS) $(SRCS_LIBFT) $(SRCS_SERVER) -o server
	@ echo "\033[38;5;205mServer compiled\033[m 🐍"


$(BONUS):
	@ gcc $(FLAGS) $(SRCS_LIBFT) $(SRCS_CLIENT_BONUS) -o client_bonus
	@ echo "\033[38;2;243;134;48mClient bonus compiled\033[0m 🐙"
	@ gcc $(FLAGS) $(SRCS_LIBFT) $(SRCS_SERVER_BONUS) -o server_bonus
	@ echo "\033[38;5;205mServer bonus compiled\033[m 🐍"

m: $(NAME)

bonus: $(BONUS)

all : $(NAME) $(BONUS)

clean_m:
	@ rm -rf client
	@ rm -rf server
	@ echo "Deleting client..."
	@ echo "Deleting server..."

clean_bonus:
	@ rm -rf client_bonus
	@ echo "Deleting client_bonus..."
	@ rm -rf server_bonus
	@ echo "Deleting server_bonus..."

fclean : clean
	@ rm -rf server
	@ rm -rf client
	@ echo "\033[31mClient deleted\033[m"
	@ echo "\033[31mServer deleted\033[m" 
	@ rm -rf server_bonus
	@ rm -rf client_bonus
	@ echo "\033[31mClient_bonus deleted\033[m"
	@ echo "\033[31mServer_bonus deleted\033[m" 

re : fclean all

.PHONY : all clean fclean re
