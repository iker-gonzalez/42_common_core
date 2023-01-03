#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks find_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mFIND MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		std::cout << "mymap containts..." << std::endl;
		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << std::endl;

		std::cout << "Looking for b..." << std::endl;
		it = mymap.find('b');
		if (it != mymap.end())
			std::cout << "b is in mymap" << std::endl;
		else
			std::cout << "b is not in  mymap" << std::endl;
		std::cout << std::endl;

		std::cout << "Looking for x..." << std::endl;
		it = mymap.find('x');
		if (it != mymap.end())
			std::cout << "x is in mymap" << std::endl;
		else
			std::cout << "x is not in  mymap" << std::endl;
		std::cout << std::endl;

		std::cout << "Looking for b..." << std::endl;
		it = mymap.find('t');
		if (it != mymap.end())
			std::cout << "t is in mymap" << std::endl;
		else
			std::cout << "t is not in  mymap" << std::endl;
		std::cout << std::endl;

		std::cout << "Looking for b..." << std::endl;
		it = mymap.find('d');
		if (it != mymap.end())
			std::cout << "d is in mymap" << std::endl;
		else
			std::cout << "d is not in  mymap" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		std::cout << "mymap containts..." << std::endl;
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << std::endl;

		std::cout << "Looking for b..." << std::endl;
		it = mymap.find('b');
		if (it != mymap.end())
			std::cout << "b is in mymap" << std::endl;
		else
			std::cout << "b is not in  mymap" << std::endl;
		std::cout << std::endl;

		std::cout << "Looking for x..." << std::endl;
		it = mymap.find('x');
		if (it != mymap.end())
			std::cout << "x is in mymap" << std::endl;
		else
			std::cout << "x is not in  mymap" << std::endl;
		std::cout << std::endl;

		std::cout << "Looking for b..." << std::endl;
		it = mymap.find('t');
		if (it != mymap.end())
			std::cout << "t is in mymap" << std::endl;
		else
			std::cout << "t is not in  mymap" << std::endl;
		std::cout << std::endl;

		std::cout << "Looking for b..." << std::endl;
		it = mymap.find('d');
		if (it != mymap.end())
			std::cout << "d is in mymap" << std::endl;
		else
			std::cout << "d is not in  mymap" << std::endl;
	}
	return (0);
}
