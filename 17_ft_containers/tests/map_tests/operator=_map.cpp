#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks operator=_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mOPERATOR= MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		std::map<char,int> second (first.begin(),first.end());
		second['z']=70;

		std::map<char,int> third (second);
		third.erase('a');
		third.erase('d');

		std::map<char,int> fourth;

		fourth['a']=10;
		fourth['b']=30;
		fourth['c']=50;
		fourth['d']=70;

		std::map<char,int> fifth;

		fifth = second;

		std::map<char,int> newOne;
		std::map<char,int> newTwo;

		newOne['x']=8;
		newOne['y']=16;
		newOne['z']=32;

		newTwo=newOne;                // second now contains 3 ints
		newOne=std::map<char,int>();  // and first is now empty

		std::cout << "Size of first:  " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
		std::cout << "Size of third:  " << third.size() << '\n';
		std::cout << "Size of fourth: " << fourth.size() << '\n';
		std::cout << "Size of fifth:  " << fifth.size() << '\n';
		std::cout << "Size of newOne: " << newOne.size() << '\n';
		std::cout << "Size of newTwo: " << newTwo.size() << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		ft::map<char,int> second (first.begin(),first.end());
		second['z']=70;

		ft::map<char,int> third (second);
		third.erase('a');
		third.erase('d');

		ft::map<char,int> fourth;

		fourth['a']=10;
		fourth['b']=30;
		fourth['c']=50;
		fourth['d']=70;

		ft::map<char,int> fifth;

		fifth = second;

		ft::map<char,int> newOne;
		ft::map<char,int> newTwo;

		newOne['x']=8;
		newOne['y']=16;
		newOne['z']=32;

		newTwo=newOne;                // second now contains 3 ints
		newOne=ft::map<char,int>();  // and first is now empty

		std::cout << "Size of first:  " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
		std::cout << "Size of third:  " << third.size() << '\n';
		std::cout << "Size of fourth: " << fourth.size() << '\n';
		std::cout << "Size of fifth:  " << fifth.size() << '\n';
		std::cout << "Size of newOne: " << newOne.size() << '\n';
		std::cout << "Size of newTwo: " << newTwo.size() << '\n';
	}
	return (0);
}
