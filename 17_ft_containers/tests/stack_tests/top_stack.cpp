#include "stack_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks top_stack_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mTOP STACK TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::stack\033[39m\033[0m" << std::endl;
		std::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		std::cout << "mystack top: " << mystack.top() << std::endl;
		mystack.push(13);
		std::cout << "mystack top: " << mystack.top() << std::endl;
		mystack.push(1);
		mystack.push(7);
		std::cout << "mystack top: " << mystack.top() << std::endl;
		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::stack\033[39m\033[0m" << std::endl;
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		std::cout << "mystack top: " << mystack.top() << std::endl;
		mystack.push(13);
		std::cout << "mystack top: " << mystack.top() << std::endl;
		mystack.push(1);
		mystack.push(7);
		std::cout << "mystack top: " << mystack.top() << std::endl;
		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	return (0);
}
