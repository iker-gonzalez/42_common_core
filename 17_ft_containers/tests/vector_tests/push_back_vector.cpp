#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks push_back_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mPUSH_BACK VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myvector.push_back (myint);
			std::cout << "push_back(" << myint << ")" << std::endl;
		} while (myint);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
		for (std::vector<int>::iterator beg = myvector.begin(); beg != myvector.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			myvector.push_back (myint);
			std::cout << "push_back(" << myint << ")" << std::endl;
		} while (myint);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
		for (ft::vector<int>::iterator beg = myvector.begin(); beg != myvector.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << std::endl;
	}
	return (0);
}
