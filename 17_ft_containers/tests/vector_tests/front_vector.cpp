#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks front_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mFRONT VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> myvector;

		myvector.push_back(78);
		std::cout << "myvector.front() is now " << myvector.front() << '\n';
		myvector.push_back(16);
		std::cout << "myvector.front() is now " << myvector.front() << '\n';

		// now front equals 78, and back 16
		myvector.front() -= myvector.back();
		std::cout << "myvector.front() is now " << myvector.front() << '\n';

		std::vector<char> first;

		first.insert(first.begin(), 'm');
		std::cout << "first.front() is now " << first.front() << '\n';
		first.insert(first.begin(), 'a');
		std::cout << "first.front() is now " << first.front() << '\n';
		first.insert(first.begin(), 'r');
		std::cout << "first.front() is now " << first.front() << '\n';
		first.front() += first.back();
		std::cout << "first.front() is now " << first.front() << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> myvector;

		myvector.push_back(78);
		std::cout << "myvector.front() is now " << myvector.front() << '\n';
		myvector.push_back(16);
		std::cout << "myvector.front() is now " << myvector.front() << '\n';

		// now front equals 78, and back 16
		myvector.front() -= myvector.back();
		std::cout << "myvector.front() is now " << myvector.front() << '\n';

		ft::vector<char> first;

		first.insert(first.begin(), 'm');
		std::cout << "first.front() is now " << first.front() << '\n';
		first.insert(first.begin(), 'a');
		std::cout << "first.front() is now " << first.front() << '\n';
		first.insert(first.begin(), 'r');
		std::cout << "first.front() is now " << first.front() << '\n';
		first.front() += first.back();
		std::cout << "first.front() is now " << first.front() << '\n';
	}
	return (0);
}
