#include "iter.hpp"

int main(int, char**)
{
	int tab[] = {0, 1, 2, 3, 4};
	iter(tab, 5, print);
	std::cout << std::endl;
	iter(tab, 5, sqrt);
	std::cout << std::endl;
	iter(tab, 5, print);
	std::cout << std::endl;
	return (0);
}