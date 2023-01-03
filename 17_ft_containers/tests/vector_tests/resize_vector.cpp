#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks resize_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mRESIZE VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> myvector;

		std::cout << "myvector size: " << myvector.size() << std::endl;
		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		std::cout << "myvector size: " << myvector.size() << std::endl;
		myvector.resize(5);
		std::cout << "myvector size: " << myvector.size() << std::endl;
		myvector.resize(8,100);
		std::cout << "myvector size: " << myvector.size() << std::endl;
		myvector.resize(12);
		std::cout << "myvector size: " << myvector.size() << std::endl;

		std::cout << "myvector contains:";
		for (unsigned int i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> myvector;

		std::cout << "myvector size: " << myvector.size() << std::endl;
		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		std::cout << "myvector size: " << myvector.size() << std::endl;
		myvector.resize(5);
		std::cout << "myvector size: " << myvector.size() << std::endl;
		myvector.resize(8,100);
		std::cout << "myvector size: " << myvector.size() << std::endl;
		myvector.resize(12);
		std::cout << "myvector size: " << myvector.size() << std::endl;

		std::cout << "myvector contains:";
		for (unsigned int i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	return (0);
}
