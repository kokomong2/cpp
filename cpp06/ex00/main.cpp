#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	ScalarConverter *converter = ScalarConverter::getInstance(argv[1]);
	try {
		converter->convert();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *converter;
	return (0);
}
