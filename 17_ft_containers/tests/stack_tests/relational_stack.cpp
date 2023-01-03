#include "stack_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks relational_stack_test");
	std::cout << "Press ENTER to continue...";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mRELATIONAL STACK TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::stack\033[39m\033[0m" << std::endl;
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200
		std::stack<int, std::vector<int> > foo_stack (foo);   // three ints with a value of 100
		std::stack<int, std::vector<int> > bar_stack (bar);   // two ints with a value of 200

		std::cout << "foo contains: ";
		for (std::vector<int>::iterator beg = foo.begin(); beg != foo.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << '\n';

		std::cout << "bar contains: ";
		for (std::vector<int>::iterator beg = bar.begin(); beg != bar.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << '\n';

		if (foo_stack==bar_stack) std::cout << "foo_stack and bar_stack are equal\n";
		if (foo_stack!=bar_stack) std::cout << "foo_stack and bar_stack are not equal\n";
		if (foo_stack< bar_stack) std::cout << "foo_stack is less than bar_stack\n";
		if (foo_stack> bar_stack) std::cout << "foo_stack is greater than bar_stack\n";
		if (foo_stack<=bar_stack) std::cout << "foo_stack is less than or equal to bar_stack\n";
		if (foo_stack>=bar_stack) std::cout << "foo_stack is greater than or equal to bar_stack\n";
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::stack\033[39m\033[0m" << std::endl;
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200
		ft::stack<int, ft::vector<int> > foo_stack (foo);   // three ints with a value of 100
		ft::stack<int, ft::vector<int> > bar_stack (bar);   // two ints with a value of 200

		std::cout << "foo contains: ";
		for (ft::vector<int>::iterator beg = foo.begin(); beg != foo.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << '\n';

		std::cout << "bar contains: ";
		for (ft::vector<int>::iterator beg = bar.begin(); beg != bar.end(); beg++)
			std::cout << *beg << ' ';
		std::cout << '\n';

		if (foo_stack==bar_stack) std::cout << "foo_stack and bar_stack are equal\n";
		if (foo_stack!=bar_stack) std::cout << "foo_stack and bar_stack are not equal\n";
		if (foo_stack< bar_stack) std::cout << "foo_stack is less than bar_stack\n";
		if (foo_stack> bar_stack) std::cout << "foo_stack is greater than bar_stack\n";
		if (foo_stack<=bar_stack) std::cout << "foo_stack is less than or equal to bar_stack\n";
		if (foo_stack>=bar_stack) std::cout << "foo_stack is greater than or equal to bar_stack\n";
	}
	return (0);
}
