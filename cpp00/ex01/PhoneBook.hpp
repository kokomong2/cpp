
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <cstdio>

# define DELIMITER "|"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	add(void);
		void	search(void);
		int		getIndex(void);
		void	updateIndex(void);
		void	showColumn(void);
		int		inputIndex(void);
		void	searchContact(int index);
	private:
		int		_index;
		int		_maxIndex;
		Contact	_contacts[8];
};

#endif