#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks at_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mAT MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<std::string,int> mymap;
		
		mymap["alpha"] = 10;
		mymap["beta"] = 10;
		mymap["gamma"] = 10;

		std::cout << "Before at...\n";
		for (std::map<std::string,int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
			std::cout << it->first << ": " << it->second << '\n';
		}
		std::cout << std::endl;

		mymap.at("alpha") = 1000;
		mymap.at("beta") = 2000;
		mymap.at("gamma") = 3000;

		std::cout << "After at...\n";
		for (std::map<std::string,int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
			std::cout << it->first << ": " << it->second << '\n';
		}
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<std::string,int> mymap;

		mymap["alpha"] = 10;
		mymap["beta"] = 10;
		mymap["gamma"] = 10;

		std::cout << "Before at...\n";
		for (ft::map<std::string,int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
			std::cout << it->first << ": " << it->second << '\n';
		}
		std::cout << std::endl;

		mymap.at("alpha") = 1000;
		mymap.at("beta") = 2000;
		mymap.at("gamma") = 3000;

		std::cout << "After at...\n";
		for (ft::map<std::string,int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
			std::cout << it->first << ": " << it->second << '\n';
		}
	}
	return (0);
}
