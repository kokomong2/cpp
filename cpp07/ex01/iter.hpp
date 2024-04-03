#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter (T *array, size_t length, void (*fn)(T&))
{
	for (size_t i = 0; i < length; i++)
	{
		fn(array[i]);
	}
}

template<typename T>
void print(T &str)
{
	std::cout << str << " ";
}

template<typename T>
void sqrt(T &num)
{
	num = num * num;
}

#endif
