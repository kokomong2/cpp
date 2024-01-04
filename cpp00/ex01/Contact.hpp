#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdio>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

std::string	ft_getline(std::string &str);
bool		checkValid(std::string str);

# endif