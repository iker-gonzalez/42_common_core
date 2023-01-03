.PHONY:	all clean fclean run

NAME		= .time_cond_make

SRCS		= init_map.cpp		\
		  constructor_map.cpp	\
		  operator=_map.cpp	\
		  begin_end_map.cpp	\
		  rbegin_rend_map.cpp	\
		  empty_map.cpp		\
		  size_map.cpp		\
		  max_size_map.cpp	\
		  operator[]_map.cpp	\
		  at_map.cpp		\
		  insert_map.cpp	\
		  erase_map.cpp		\
		  swap_map.cpp		\
		  clear_map.cpp		\
		  key_comp_map.cpp	\
		  value_comp_map.cpp	\
		  find_map.cpp		\
		  count_map.cpp		\
		  lower_bound_map.cpp	\
		  upper_bound_map.cpp	\
		  equal_range_map.cpp	\
		  get_allocator_map.cpp

OBJS		= $(SRCS:.cpp=.o)

CXX		= clang++

CXXFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	@ echo "\033[1m\033[35mPrograms have been compiled...\033[39m\033[0m"
	$(CXX) $(CXXFLAGS) init_map.o -o init_map_test
	$(CXX) $(CXXFLAGS) constructor_map.o -o constructor_map_test
	$(CXX) $(CXXFLAGS) operator=_map.o -o operator=_map_test
	$(CXX) $(CXXFLAGS) begin_end_map.o -o begin_end_map_test
	$(CXX) $(CXXFLAGS) rbegin_rend_map.o -o rbegin_rend_map_test
	$(CXX) $(CXXFLAGS) empty_map.o -o empty_map_test
	$(CXX) $(CXXFLAGS) size_map.o -o size_map_test
	$(CXX) $(CXXFLAGS) max_size_map.o -o max_size_map_test
	$(CXX) $(CXXFLAGS) operator\[\]_map.o -o operator\[\]_map_test
	$(CXX) $(CXXFLAGS) at_map.o -o at_map_test
	$(CXX) $(CXXFLAGS) insert_map.o -o insert_map_test
	$(CXX) $(CXXFLAGS) erase_map.o -o erase_map_test
	$(CXX) $(CXXFLAGS) swap_map.o -o swap_map_test
	$(CXX) $(CXXFLAGS) clear_map.o -o clear_map_test
	$(CXX) $(CXXFLAGS) key_comp_map.o -o key_comp_map_test
	$(CXX) $(CXXFLAGS) value_comp_map.o -o value_comp_map_test
	$(CXX) $(CXXFLAGS) find_map.o -o find_map_test
	$(CXX) $(CXXFLAGS) count_map.o -o count_map_test
	$(CXX) $(CXXFLAGS) lower_bound_map.o -o lower_bound_map_test
	$(CXX) $(CXXFLAGS) upper_bound_map.o -o upper_bound_map_test
	$(CXX) $(CXXFLAGS) equal_range_map.o -o equal_range_map_test
	$(CXX) $(CXXFLAGS) get_allocator_map.o -o get_allocator_map_test
	@ touch .time_cond_make
	@ echo "\033[1m\033[35mExecutables have been compiled...\033[39m\033[0m"

clean:
	@ echo "\033[1m\033[35mRemoving map files...\033[39m\033[0m"
	@ $(RM) $(OBJS)
	@ $(RM) .time_cond_make

fclean:		clean
	@ echo "\033[1m\033[35mRemoving map executables...\033[39m\033[0m"
	@ $(RM) *_map_test

re:		fclean all

run:		all
	@ clear
	@ ./init_map_test
	@ ./constructor_map_test
	@ ./operator=_map_test
	@ ./begin_end_map_test
	@ ./rbegin_rend_map_test
	@ ./empty_map_test
	@ ./size_map_test
	@ ./max_size_map_test
	@ ./operator\[\]_map_test
	@ ./at_map_test
	@ ./insert_map_test
	@ ./erase_map_test
	@ ./swap_map_test
	@ ./clear_map_test
	@ ./key_comp_map_test
	@ ./value_comp_map_test
	@ ./find_map_test
	@ ./count_map_test
	@ ./lower_bound_map_test
	@ ./upper_bound_map_test
	@ ./equal_range_map_test
	@ ./get_allocator_map_test
	@ ./init_map_test
