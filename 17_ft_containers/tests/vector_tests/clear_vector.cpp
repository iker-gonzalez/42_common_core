#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks clear_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mCLEAR VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector size: " << myvector.size() << std::endl;
		std::cout << "myvector capacity: " << myvector.capacity() << std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		std::cout << std::endl << "myvector.clear()" << std::endl;
		std::cout << std::endl;
		std::cout << "myvector size: " << myvector.size() << std::endl;
		std::cout << "myvector capacity: " << myvector.capacity() << std::endl;
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector size: " << myvector.size() << std::endl;
		std::cout << "myvector capacity: " << myvector.capacity() << std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector size: " << myvector.size() << std::endl;
		std::cout << "myvector capacity: " << myvector.capacity() << std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		std::cout << std::endl << "myvector.clear()" << std::endl;
		std::cout << std::endl;
		std::cout << "myvector size: " << myvector.size() << std::endl;
		std::cout << "myvector capacity: " << myvector.capacity() << std::endl;
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector size: " << myvector.size() << std::endl;
		std::cout << "myvector capacity: " << myvector.capacity() << std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	return (0);
}
