#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks erase_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mERASE MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		std::cout << "BEFORE ERASE" << std::endl;
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ")  ";
		std::cout << std::endl << std::endl;

		std::cout << "ERASING BY POSITION --> b" << std::endl;
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ")  ";
		std::cout << std::endl << std::endl;

		std::cout << "ERASING BY KEY      --> c" << std::endl;
		mymap.erase ('c');                  // erasing by key
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ")  ";
		std::cout << std::endl << std::endl;

		std::cout << "ERASING BY RANGE    --> e to end" << std::endl;
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ")  ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		std::cout << "BEFORE ERASE" << std::endl;
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ")  ";
		std::cout << std::endl << std::endl;

		std::cout << "ERASING BY POSITION --> b" << std::endl;
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ")  ";
		std::cout << std::endl << std::endl;

		std::cout << "ERASING BY KEY      --> c" << std::endl;
		mymap.erase ('c');                  // erasing by key
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ")  ";
		std::cout << std::endl << std::endl;

		std::cout << "ERASING BY RANGE    --> e to end" << std::endl;
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ")  ";
		std::cout << std::endl;
	}
	return (0);
}
