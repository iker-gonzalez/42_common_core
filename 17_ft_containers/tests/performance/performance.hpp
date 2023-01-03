#ifndef PERFORMANCE_HPP

#	include <ctime>

class Timer
{

	std::clock_t _start;

public:
	Timer();
	Timer(const Timer &ref);
	Timer &operator=(const Timer &ref);
	~Timer();
	void start();
	std::clock_t stop();
};

#	include "../../containers/map.hpp"
#	include "../../containers/stack.hpp"
#	include "../../containers/vector.hpp"
#	include <iostream>
#	include <map>
#	include <stack>
#	include <vector>

// Map benchmark
// mapType must be a map to int, bool.
template <typename MapType>
std::clock_t insert_growing(size_t times, MapType map)
{
	Timer t;
	t.start();

	for (size_t i = 0; i < times; i++)
	{
		map[i] = true; // insert a constantly growing range of integers
		// which is a worst-case scenario for an unbalanced map.
		map.find(i);
	}

	// Copy-construction and destruction
	{
		MapType new_map(map);
	}

	return t.stop();
}

// Vector benchmark
// Vector must be a vector of ints
template <typename VectorType>
std::clock_t v_insert_growing(size_t times, VectorType vector)
{
	Timer t;
	t.start();

	int tmp = 0;

	for (size_t i = 0; i < times; i++)
	{
		vector.push_back(i); // insert a constantly growing range of integers
		tmp = vector[i];
	}

	{

		VectorType newVector(vector); // copy and destruction
	}

	vector.erase(vector.begin(), vector.end()); // erase
	vector.resize(100);
	vector.clear();

	for (size_t i = 0; i < times; i++)
	{
		vector.push_back(i);
		tmp = vector.at(i);
	}
	
	return t.stop();
}

template <typename StackType>
std::clock_t s_insert_growing(size_t times, StackType stack)
{
	Timer t;
	t.start();

	int tmp = 0;

	for (size_t i = 0; i < times; i++)
	{
		stack.push(i); // insert a constantly growing range of integers
	}

	{
		StackType newStack(stack); //copy and destruction
	}

	for (size_t i = 0; i < times; i++)
	{
		tmp = stack.top();
		stack.pop();
	}

	return t.stop();
}

void performance_map();
void performance_vector();
void performance_stack();

#endif // !PERFORMANCE_HPP
