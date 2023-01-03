#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks value_comp_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mVALUE_COMP MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char, int>	mymap;
		std::pair<char, int>	pair('f', 0);

		mymap['a'] = 200;
		mymap['b'] = 300;
		mymap['l'] = 400;
		mymap['o'] = 500;

		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << std::endl;

		for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		{
			std::pair<char, int>	tmp_pair(it->first, it->second);
			std::cout << it->first << " > f ==>  " << mymap.value_comp()(tmp_pair, pair) << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char, int>	mymap;
		ft::pair<char, int>	pair('f', 0);

		mymap['a'] = 200;
		mymap['b'] = 300;
		mymap['l'] = 400;
		mymap['o'] = 500;

		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << std::endl;

		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		{
			ft::pair<char, int>	tmp_pair(it->first, it->second);
			std::cout << it->first << " > f ==>  " << mymap.value_comp()(tmp_pair, pair) << std::endl;
		}
	}
	return (0);
}
