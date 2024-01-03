#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command: ";
		ft_getline(command);
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}

std::string	ft_getline(std::string &str)
{
	std::getline(std::cin, str);
	if (std::cin.fail())
	{
		std::cin.clear();
		std::clearerr(stdin);
	}
	return (str); 
}
