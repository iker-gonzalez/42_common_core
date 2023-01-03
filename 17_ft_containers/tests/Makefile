# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 08:00:32 by ikgonzal          #+#    #+#              #
#    Updated: 2022/12/11 13:12:16 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re run vector stack map performance

all:
	@ clear
	@ echo "\033[1m\033[33mCOMPILING VECTOR AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make -C ./vector_tests/
	@ clear
	@ echo "\033[1m\033[33mCOMPILING STACK AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make -C ./stack_tests/
	@ clear
	@ echo "\033[1m\033[33mCOMPILING MAP AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make -C ./map_tests/

clean:
	@ make clean -C ./vector_tests/
	@ make clean -C ./stack_tests/
	@ make clean -C ./map_tests/

fclean:
	@ make fclean -C ./vector_tests/
	@ make fclean -C ./stack_tests/
	@ make fclean -C ./map_tests/

re:		all fclean

run:		all
	@ clear
	@ make run -C ./vector_tests/
	@ make run -C ./stack_tests/
	@ make run -C ./map_tests/
	@ clear
	@ make -C ./performance/

vector:
	@ echo "\033[1m\033[33mCOMPILING VECTOR AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make run -C ./vector_tests/
	@ make fclean -C ./vector_tests/
	
stack:
	@ echo "\033[1m\033[33mCOMPILING STACK AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make run -C ./stack_tests/
	@ make fclean -C ./stack_tests/

map:
	@ echo "\033[1m\033[33mCOMPILING MAP AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make run -C ./map_tests/
	@ make fclean -C ./map_tests/

performance:
	@ echo "\033[1m\033[33mRUNNING PERFORMANCE\033[39m\033[0m"
	@ make -C ./performance/