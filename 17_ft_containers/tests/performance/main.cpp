#include "performance.hpp"
#include <unistd.h>

int main(void)
{
	std::cout << "Performance: " << std::endl
			  << std::endl;

	performance_map();
	performance_vector();
	performance_stack();
}
