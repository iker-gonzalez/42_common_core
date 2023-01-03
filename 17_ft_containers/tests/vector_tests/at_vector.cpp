#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks at_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mAT VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<char> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i + 'A';

		std::cout << "myvector contains:" << std::endl;
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << "at(" << i << "): "  << myvector.at(i) << std::endl;
		std::cout << '\n';

		std::cout << "myvector.at(0): " << myvector.at(0) << std::endl;
		std::cout << "myvector.at(4): " << myvector.at(4) << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<char> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i + 'A';

		std::cout << "myvector contains:" << std::endl;
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << "at(" << i << "): "  << myvector.at(i) << std::endl;
		std::cout << '\n';

		std::cout << "myvector.at(0): " << myvector.at(0) << std::endl;
		std::cout << "myvector.at(4): " << myvector.at(4) << std::endl;
	}
	return (0);
}
