#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks constructor_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

struct	classcomp
{
	bool operator()(const char& lhs, const char& rhs) const
	{
		return (lhs > rhs);
	}
};

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mCONSTRUCTOR MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int> first;

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		std::map<char,int> second (first.begin(),first.end());

		std::map<char,int> third (second);

		std::map<char,int,classcomp> fourth;

		fourth['a']=10;
		fourth['b']=30;
		fourth['c']=50;
		fourth['d']=70;

		std::map<char,int> fifth;

		fifth = second;

		std::cout << "The contents of first are (initialized empty):                      ";
		for (std::map<char, int>::iterator it = first.begin(); it != first.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;

		std::cout << "The contents of second are (initialized with iterators):            ";
		for (std::map<char, int>::iterator it = second.begin(); it != second.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;

		std::cout << "The contents of third are (initialized with copy constructor):      ";
		for (std::map<char, int>::iterator it = third.begin(); it != third.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;

		std::cout << "The contents of fourth are (initialized with comp func):            ";
		for (std::map<char, int, classcomp>::iterator it = fourth.begin(); it != fourth.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;

		std::cout << "The contents of fifth are (initizalized with assignation operator): ";
		for (std::map<char, int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;

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

		ft::map<char,int> third (second);

		ft::map<char,int,classcomp> fourth;

		fourth['a']=10;
		fourth['b']=30;
		fourth['c']=50;
		fourth['d']=70;

		ft::map<char,int> fifth;

		fifth = second;

		std::cout << "The contents of first are (initialized empty):                      ";
		for (ft::map<char, int>::iterator it = first.begin(); it != first.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;

		std::cout << "The contents of second are (initialized with iterators):            ";
		for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;

		std::cout << "The contents of third are (initialized with copy constructor):      ";
		for (ft::map<char, int>::iterator it = third.begin(); it != third.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;

		std::cout << "The contents of fourth are (initialized with comp func):            ";
		for (ft::map<char, int, classcomp>::iterator it = fourth.begin(); it != fourth.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;

		std::cout << "The contents of fifth are (initizalized with assignation operator): ";
		for (ft::map<char, int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << '(' << it->first << ", " << it->second << ") ";
		std::cout << std::endl;
	}
	return (0);
}
