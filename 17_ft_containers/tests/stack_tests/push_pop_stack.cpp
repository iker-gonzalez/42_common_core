#include "stack_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks push_pop_stack_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mPUSH & POP STACK TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::stack\033[39m\033[0m" << std::endl;
		std::stack<int> mystack;

		std::cout << "mystack size: " << mystack.size() << std::endl;
		for (int i=0; i<5; ++i)
		{
			mystack.push(i);
			std::cout << "push: " << i << std::endl;
		}
		std::cout << "mystack size: " << mystack.size() << std::endl;

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
		std::cout << "mystack size: " << mystack.size() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::stack\033[39m\033[0m" << std::endl;
		ft::stack<int> mystack;

		std::cout << "mystack size: " << mystack.size() << std::endl;
		for (int i=0; i<5; ++i)
		{
			mystack.push(i);
			std::cout << "push: " << i << std::endl;
		}
		std::cout << "mystack size: " << mystack.size() << std::endl;

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
		std::cout << "mystack size: " << mystack.size() << std::endl;
	}
	return (0);
}
