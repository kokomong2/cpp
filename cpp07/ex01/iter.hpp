#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter (T *array, size_t length, F fn)
{
	for (size_t i = 0; i < length; i++)
	{
		fn(array[i]);
	}
}

template<typename T>
void printIter(T &str)
{
	std::cout << str << " ";
}

#endif
