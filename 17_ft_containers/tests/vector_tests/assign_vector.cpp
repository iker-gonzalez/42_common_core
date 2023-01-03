#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks assign_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mASSIGN VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		std::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "Size of first: " << int (first.size()) << '\n';
		for (std::vector<int>::iterator begin = first.begin(); begin != first.end(); begin++)
			std::cout << *begin << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Size of second: " << int (second.size()) << '\n';
		for (std::vector<int>::iterator begin = second.begin(); begin != second.end(); begin++)
			std::cout << *begin << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Size of third: " << int (third.size()) << '\n';
		for (std::vector<int>::iterator begin = third.begin(); begin != third.end(); begin++)
			std::cout << *begin << " ";
		std::cout << std::endl << std::endl;

		first.assign(1, 1);
		second.assign(2, 2);
		third.assign(100, 3);

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		ft::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "Size of first: " << int (first.size()) << '\n';
		for (ft::vector<int>::iterator begin = first.begin(); begin != first.end(); begin++)
			std::cout << *begin << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Size of second: " << int (second.size()) << '\n';
		for (ft::vector<int>::iterator begin = second.begin(); begin != second.end(); begin++)
			std::cout << *begin << " ";
		std::cout << std::endl << std::endl;

		std::cout << "Size of third: " << int (third.size()) << '\n';
		for (ft::vector<int>::iterator begin = third.begin(); begin != third.end(); begin++)
			std::cout << *begin << " ";
		std::cout << std::endl << std::endl;

		first.assign(1, 1);
		second.assign(2, 2);
		third.assign(100, 3);

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	}
	return (0);
}
