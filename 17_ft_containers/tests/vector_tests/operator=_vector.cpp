#include "vector_tests.hpp"

void	leaks(void)
{
	std::cout << std::endl;
	std::cout << "\033[1m\033[31mLEAKS\033[39m\033[0m" << std::endl;
	system("leaks operator=_vector_test");
	std::cout << "\033[1mPress ENTER to continue...\033[0m";
	getchar();
}

int	main(void)
{
	system("clear");
	atexit(leaks);
	std::cout << "\033[1m\033[33mOPERATOR= VECTOR TEST\033[39m\033[0m" << std::endl;
	{
		std::cout << "\033[1m\033[35mstd::vector\033[39m\033[0m" << std::endl;
		std::vector<int> emp;
		std::vector<int> foo (3,0);
		std::vector<int> bar (5,0);

		std::cout << "Size of emp: " << int(emp.size()) << '\n';
		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';

		emp = std::vector<int>(bar.begin(), bar.end());
		bar = foo;
		foo = std::vector<int>();

		std::cout << "Size of emp: " << int(emp.size()) << '\n';
		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}
	std::cout << std::endl;
	{
		std::cout << "\033[1m\033[35mft::vector\033[39m\033[0m" << std::endl;
		ft::vector<int> emp;
		ft::vector<int> foo (3,0);
		ft::vector<int> bar (5,0);

		std::cout << "Size of foo: " << int(emp.size()) << '\n';
		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';

		emp = ft::vector<int>(bar.begin(), bar.end());
		bar = foo;
		foo = ft::vector<int>();

		std::cout << "Size of foo: " << int(emp.size()) << '\n';
		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}
	return (0);
}
