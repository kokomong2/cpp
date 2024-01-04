
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_maxIndex = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "First name: ";
	ft_getline(firstName);
	if (checkValid(firstName) == false)
	{
		std::cout << "Invalid first name." << std::endl;
		return ;
	}
	std::cout << "Last name: ";
	ft_getline(lastName);
	if (checkValid(lastName) == false)
	{
		std::cout << "Invalid last name." << std::endl;
		return ;
	}
	std::cout << "Nickname: ";
	ft_getline(nickname);
	if (checkValid(nickname) == false)
	{
		std::cout << "Invalid nickname." << std::endl;
		return ;
	}
	std::cout << "Phone number: ";
	ft_getline(phoneNumber);
	if (checkValid(phoneNumber) == false)
	{
		std::cout << "Invalid phone number." << std::endl;
		return ;
	}
	std::cout << "Darkest secret: ";
	ft_getline(darkestSecret);
	if (checkValid(darkestSecret) == false)
	{
		std::cout << "Invalid darkest secret." << std::endl;
		return ;
	}
	this->_contacts[this->_index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->updateIndex();
}

int	PhoneBook::getIndex(void)
{
	return (this->_index);
}

void	PhoneBook::updateIndex(void)
{
	if (this->_index == 7)
		this->_index = 0;
	else
	{
		this->_index++;
		this->_maxIndex++;
	}
}

void	PhoneBook::search(void)
{
	if (this->_maxIndex == 0)
	{
		std::cout << "No contact to show." << std::endl;
		return ;
	}
	this->showColumn();
	for (int i = 0; i < this->_maxIndex; i++)
		this->searchContact(i);
	int	index = this->inputIndex();
	if (index == -1)
		std::cout << "Invalid index." << std::endl;
	else if (index >= 0 && index < this->_maxIndex)
	{
		this->showDetail(index);
	}
	else
		std::cout << "Index out of range." << std::endl;
}

void	PhoneBook::showColumn(void)
{
	
	std::cout << std::setw(10) << "index" << DELIMITER;
	std::cout << std::setw(10) << "first name" << DELIMITER;
	std::cout << std::setw(10) << "last name" << DELIMITER;
	std::cout << std::setw(10) << "nickname" << std::endl;
	std::cout << "----------|----------|----------|----------\n";
}

int	PhoneBook::inputIndex(void)
{
	std::string	index;

	std::cout << "Enter an index between 0 and 7 : ";
	ft_getline(index);
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '9')
		return (index[0] - '0');
	else
		return (-1);
}

void	PhoneBook::searchContact(int index)
{
	std::cout << std::setw(10) << index << DELIMITER;
	if (this->_contacts[index].getFirstName().length() > 10)
		std::cout << std::setw(10) << this->_contacts[index].getFirstName().substr(0, 9) + "." << DELIMITER;
	else
		std::cout << std::setw(10) << this->_contacts[index].getFirstName() << DELIMITER;
	if (this->_contacts[index].getLastName().length() > 10)
		std::cout << std::setw(10) << this->_contacts[index].getLastName().substr(0, 9) + "." << DELIMITER;
	else
		std::cout << std::setw(10) << this->_contacts[index].getLastName() << DELIMITER;
	if (this->_contacts[index].getNickname().length() > 10)
		std::cout << std::setw(10) << this->_contacts[index].getNickname().substr(0, 9) + "." << std::endl;
	else
		std::cout << std::setw(10) << this->_contacts[index].getNickname() << std::endl;
}

void	PhoneBook::showDetail(int index)
{
	std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}