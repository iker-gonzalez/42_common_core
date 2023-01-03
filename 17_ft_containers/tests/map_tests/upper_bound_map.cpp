#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks upper_bound_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mUPPER_BOUND MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		std::cout << "lower bound of a --> ";
		itlow=mymap.upper_bound ('a');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of b --> ";
		itlow=mymap.upper_bound ('b');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of d --> ";
		itlow=mymap.upper_bound ('d');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of < --> ";
		itlow=mymap.upper_bound ('<');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of e --> ";
		itlow=mymap.upper_bound ('e');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of g --> ";
		itlow=mymap.upper_bound ('g');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		std::cout << "lower bound of a --> ";
		itlow=mymap.upper_bound ('a');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of b --> ";
		itlow=mymap.upper_bound ('b');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of d --> ";
		itlow=mymap.upper_bound ('d');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of < --> ";
		itlow=mymap.upper_bound ('<');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of e --> ";
		itlow=mymap.upper_bound ('e');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;

		std::cout << "lower bound of g --> ";
		itlow=mymap.upper_bound ('g');
		std::cout << '(' << itlow->first << ", " << itlow->second << ')' << std::endl;
	}
	return (0);
}
