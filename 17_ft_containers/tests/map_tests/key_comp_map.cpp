#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks key_comp_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mKEY_COMP MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char, int, std::greater<char> >		mymap;
		std::map<char, int, std::greater<char> >::key_compare	key = mymap.key_comp();

		mymap['a'] = 100;
		mymap['b'] = 300;
		mymap['l'] = 400;
		mymap['o'] = 500;

		for (std::map<char, int, std::greater<char> >::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << std::endl;

		for (std::map<char, int, std::greater<char> >::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << it->first << " > f ==>  " << key(it->first, 'f') << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char, int, std::greater<char> >		mymap;
		ft::map<char, int, std::greater<char> >::key_compare	key = mymap.key_comp();

		mymap['a'] = 100;
		mymap['b'] = 300;
		mymap['l'] = 400;
		mymap['o'] = 500;

		for (ft::map<char, int, std::greater<char> >::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << std::endl;

		for (ft::map<char, int, std::greater<char> >::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << it->first << " > f ==>  " << key(it->first, 'f') << std::endl;
	}
	return (0);
}
