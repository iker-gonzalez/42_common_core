#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks size_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mSIZE MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int> first;
		
		first['a']=101;
		first['b']=202;
		first['c']=302;
	       	
		std::map<char,int> second(first);
		std::map<char,int> third = first;

		second.erase('b');

		third['e']=3;
		third['t']=67;
		third['o']=3;

		std::cout << "first.size() is  " << first.size() << '\n';
		std::cout << "second.size() is " << second.size() << '\n';
		std::cout << "third.size() is  " << third.size() << '\n';

		first.erase('a');
		first.erase('b');
		first.erase('c');

		std::cout << "first.size() is  " << first.size() << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char,int> first;

		first['a']=101;
		first['b']=202;
		first['c']=302;

		ft::map<char,int> second(first);
		ft::map<char,int> third = first;

		second.erase('b');

		third['e']=3;
		third['t']=67;
		third['o']=3;

		std::cout << "first.size() is  " << first.size() << '\n';
		std::cout << "second.size() is " << second.size() << '\n';
		std::cout << "third.size() is  " << third.size() << '\n';

		first.erase('a');
		first.erase('b');
		first.erase('c');

		std::cout << "first.size() is  " << first.size() << '\n';
	}
	return (0);
}
