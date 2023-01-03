#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks constructor_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mCONSTRUCTOR VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> first;                                // empty vector of ints
		std::vector<int> second (4,100);                       // four ints with value 100
		std::vector<int> third (second.begin(),second.end());  // iterating through second
		std::vector<int> fourth (third);                       // a copy of third

		std::cout << "The contents of first are:";
		for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "The contents of second are:";
		for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "The contents of third are:";
		for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "The contents of fourth are:";
		for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

       		std::cout << "The contents of fifth are:";
		for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> first;                                // empty vector of ints
		ft::vector<int> second (4,100);                       // four ints with value 100
		ft::vector<int> third (second.begin(),second.end());  // iterating through second
		ft::vector<int> fourth (third);                       // a copy of third

		std::cout << "The contents of first are:";
		for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "The contents of second are:";
		for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "The contents of third are:";
		for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "The contents of fourth are:";
		for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

       		std::cout << "The contents of fifth are:";
		for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	return (0);
}
