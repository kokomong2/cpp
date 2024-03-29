#include <iostream>
#include "Converter.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	Converter *converter = Converter::getInstance();

	Data *data = converter->getData(av[1]);
	uintptr_t ptr = converter->serialize(data);
	Data *data2 = converter->deserialize(ptr);

	std::cout << "Data: " << data->name << std::endl;
	std::cout << "Data2: " << data2->name << std::endl;

	return (0);
}