#include "stack_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks empty_stack_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mEMPTY STACK TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::stack\033[39m\033[0m" << std::endl;
		std::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		std::cout << "mystack size: " << mystack.size() << std::endl;
		std::cout << "mystack empty? " << mystack.empty() << std::endl;

		std::cout << "Init bool: ";
		while (!mystack.empty())
		{
			std::cout << mystack.top() << " ";
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << '\n';

		std::cout << "total: " << sum << '\n';
		std::cout << std::endl << "mystack size: " << mystack.size() << std::endl;
		std::cout << "mystack empty? " << mystack.empty() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::stack\033[39m\033[0m" << std::endl;
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		std::cout << "mystack size: " << mystack.size() << std::endl;
		std::cout << "mystack empty? " << mystack.empty() << std::endl;

		std::cout << "Init bool: ";
		while (!mystack.empty())
		{
			std::cout << mystack.top() << " ";
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << '\n';

		std::cout << "total: " << sum << '\n';
		std::cout << std::endl << "mystack size: " << mystack.size() << std::endl;
		std::cout << "mystack empty? " << mystack.empty() << std::endl;
	}
	return (0);
}
