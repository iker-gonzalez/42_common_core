#include "map_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks equal_range_map_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mEQUAL_RANGE MAP TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::map\033[39m\033[0m" << std::endl;
		std::map<char,int>							mymap;
		std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator>	itlow;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		std::cout << "equal range of a\n";
		itlow=mymap.equal_range ('a');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;

		std::cout << "equal range of b\n";
		itlow=mymap.equal_range ('b');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;

		std::cout << "equal range of d\n";
		itlow=mymap.equal_range ('d');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;

		std::cout << "equal range of <\n";
		itlow=mymap.equal_range ('<');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;

		std::cout << "equal range of e\n";
		itlow=mymap.equal_range ('e');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::map\033[39m\033[0m" << std::endl;
		ft::map<char,int>							mymap;
		ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator>	itlow;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		std::cout << "equal range of a\n";
		itlow=mymap.equal_range ('a');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;

		std::cout << "equal range of b\n";
		itlow=mymap.equal_range ('b');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;

		std::cout << "equal range of d\n";
		itlow=mymap.equal_range ('d');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;

		std::cout << "equal range of <\n";
		itlow=mymap.equal_range ('<');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;

		std::cout << "equal range of e\n";
		itlow=mymap.equal_range ('e');
		std::cout << "lower bound points to: ";
		std::cout << itlow.first->first << " => " << itlow.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << itlow.second->first << " => " << itlow.second->second << '\n';
		std::cout << std::endl;
	}
	return (0);
}
