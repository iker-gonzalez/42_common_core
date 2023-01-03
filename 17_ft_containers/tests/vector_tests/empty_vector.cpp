#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks empty_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mEMPTY VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		if (myvector.empty())
			std::cout << "myvector is empty - size: " << myvector.size() << std::endl;
		else
			std::cout << "myvector not empty - size: " << myvector.size() << std::endl;
		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}
		std::cout << "total: " << sum << '\n';
		if (myvector.empty())
			std::cout << "myvector is empty - size: " << myvector.size() << std::endl;
		else
			std::cout << "myvector not empty - size: " << myvector.size() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		if (myvector.empty())
			std::cout << "myvector is empty - size: " << myvector.size() << std::endl;
		else
			std::cout << "myvector not empty - size: " << myvector.size() << std::endl;
		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}
		std::cout << "total: " << sum << '\n';
		if (myvector.empty())
			std::cout << "myvector is empty - size: " << myvector.size() << std::endl;
		else
			std::cout << "myvector not empty - size: " << myvector.size() << std::endl;
	}
	return (0);
}
