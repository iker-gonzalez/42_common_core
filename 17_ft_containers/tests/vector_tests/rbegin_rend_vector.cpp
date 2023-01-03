#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks rbegin_rend_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mRBEGIN REND VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> first (5);  // 5 default-constructed ints

		int i=0;

		std::vector<int>::reverse_iterator rit = first.rbegin();
		for (; rit!= first.rend(); ++rit)
			*rit = ++i;

		std::cout << "first contains:";
		for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::vector<int> second(first);
		second.resize(10, 13);

		std::cout << "second contains:";
		for (std::vector<int>::reverse_iterator it = second.rbegin(); it != second.rend(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::vector<char> third(10);

		char c='a';

		std::vector<char>::reverse_iterator cit = third.rbegin();
		for(; cit!= third.rend(); ++cit)
			*cit = ++i + c;

		std::cout << "third contains:";
		for (std::vector<char>::iterator it = third.begin(); it != third.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> first (5);  // 5 default-constructed ints

		int i=0;

		ft::vector<int>::reverse_iterator rit = first.rbegin();
		for (; rit!= first.rend(); ++rit)
			*rit = ++i;

		std::cout << "first contains:";
		for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		ft::vector<int> second(first);
		second.resize(10, 13);

		std::cout << "second contains:";
		for (ft::vector<int>::reverse_iterator it = second.rbegin(); it != second.rend(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		ft::vector<char> third(10);

		char c='a';

		ft::vector<char>::reverse_iterator cit = third.rbegin();
		for(; cit!= third.rend(); ++cit)
			*cit = ++i + c;

		std::cout << "third contains:";
		for (ft::vector<char>::iterator it = third.begin(); it != third.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	return (0);
}
