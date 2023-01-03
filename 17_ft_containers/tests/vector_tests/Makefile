.PHONY:	all clean fclean run

NAME		= .time_cond_make

SRCS		= init_vector.cpp		\
		  constructor_vector.cpp	\
		  operator=_vector.cpp		\
		  begin_end_vector.cpp		\
		  rbegin_rend_vector.cpp	\
		  size_vector.cpp		\
		  max_size_vector.cpp		\
		  resize_vector.cpp		\
		  capacity_vector.cpp		\
		  empty_vector.cpp		\
		  reserve_vector.cpp		\
		  operator[]_vector.cpp		\
		  at_vector.cpp			\
		  front_vector.cpp		\
		  back_vector.cpp		\
		  assign_vector.cpp		\
		  push_back_vector.cpp		\
		  insert_vector.cpp		\
		  erase_vector.cpp		\
		  swap_vector.cpp		\
		  clear_vector.cpp		\
		  get_allocator_vector.cpp	\
		  relational_vector.cpp

OBJS		= $(SRCS:.cpp=.o)

CXX		= clang++

CXXFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	@ echo "\033[1m\033[35mPrograms have been compiled...\033[39m\033[0m"
	$(CXX) $(CXXFLAGS) init_vector.o -o init_vector_test
	$(CXX) $(CXXFLAGS) constructor_vector.o -o constructor_vector_test
	$(CXX) $(CXXFLAGS) operator=_vector.o -o operator=_vector_test
	$(CXX) $(CXXFLAGS) begin_end_vector.o -o begin_end_vector_test
	$(CXX) $(CXXFLAGS) rbegin_rend_vector.o -o rbegin_rend_vector_test
	$(CXX) $(CXXFLAGS) size_vector.o -o size_vector_test
	$(CXX) $(CXXFLAGS) max_size_vector.o -o max_size_vector_test
	$(CXX) $(CXXFLAGS) resize_vector.o -o resize_vector_test
	$(CXX) $(CXXFLAGS) capacity_vector.o -o capacity_vector_test
	$(CXX) $(CXXFLAGS) empty_vector.o -o empty_vector_test
	$(CXX) $(CXXFLAGS) reserve_vector.o -o reserve_vector_test
	$(CXX) $(CXXFLAGS) operator\[\]_vector.o -o operator\[\]_vector_test
	$(CXX) $(CXXFLAGS) at_vector.o -o at_vector_test
	$(CXX) $(CXXFLAGS) front_vector.o -o front_vector_test
	$(CXX) $(CXXFLAGS) back_vector.o -o back_vector_test
	$(CXX) $(CXXFLAGS) assign_vector.o -o assign_vector_test
	$(CXX) $(CXXFLAGS) push_back_vector.o -o push_back_vector_test
	$(CXX) $(CXXFLAGS) insert_vector.o -o insert_vector_test
	$(CXX) $(CXXFLAGS) erase_vector.o -o erase_vector_test
	$(CXX) $(CXXFLAGS) swap_vector.o -o swap_vector_test
	$(CXX) $(CXXFLAGS) clear_vector.o -o clear_vector_test
	$(CXX) $(CXXFLAGS) get_allocator_vector.o -o get_allocator_vector_test
	$(CXX) $(CXXFLAGS) relational_vector.o -o relational_vector_test
	@ touch .time_cond_make
	@ echo "\033[1m\033[35mExecutables have been created...\033[39m\033[0m"

clean:
	@ echo "\033[1m\033[31mRemoving vector files...\033[39m\033[0m"
	@ $(RM) $(OBJS)
	@ $(RM) .time_cond_make

fclean:		clean
	@ echo "\033[1m\033[31mRemoving vector executables...\033[39m\033[0m"
	@ $(RM) *_vector_test

re:		fclean all

run:		all
	@ clear
	@ ./init_vector_test
	@ ./constructor_vector_test
	@ ./operator=_vector_test
	@ ./begin_end_vector_test
	@ ./rbegin_rend_vector_test
	@ ./size_vector_test
	@ ./max_size_vector_test
	@ ./resize_vector_test
	@ ./capacity_vector_test
	@ ./empty_vector_test
	@ ./reserve_vector_test
	@ ./operator\[\]_vector_test
	@ ./at_vector_test
	@ ./front_vector_test
	@ ./back_vector_test
	@ ./assign_vector_test
	@ ./push_back_vector_test
	@ ./insert_vector_test
	@ ./erase_vector_test
	@ ./swap_vector_test
	@ ./clear_vector_test
	@ ./get_allocator_vector_test
	@ ./relational_vector_test
	@ ./init_vector_test
