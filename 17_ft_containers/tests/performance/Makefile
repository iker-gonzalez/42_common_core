.PHONY: all clean fclean re debug debugflags

NAME		= a.out

NOCOL		= \033[0m
ORG		= \033[0;33m
GRN		= \033[1;32m
CYN		= \033[0;36m

SRCS		= main.cpp performance.cpp
OBJS		= $(SRCS:.cpp=.o)
HEADER		= -I.

CXX		= clang++
CXXFLAGS	= -std=c++98 $(HEADER)
DEBUGFLAGS	= -g -fsanitize=address

MSG_SUCCESS	= echo -e "$(GRN)=> Success!$(NOCOL)"
MSG_DEBUG	= echo -e "$(CYN)=> Debug mode ON$(NOCOL)"

all:			$(NAME)

$(NAME):	$(OBJS)
		@$(CXX) $(CXXFLAGS) $^ -o $@
		@$(MSG_SUCCESS)
		@./a.out
		@make fclean

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all
