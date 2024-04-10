#include "iter.hpp"

int main(int, char**)
{
	int tab[] = {0, 1, 2, 3, 4};
	std::cout << "Original array: " << std::endl;
	iter(tab, 5, printIter<int>);
	return (0);
}