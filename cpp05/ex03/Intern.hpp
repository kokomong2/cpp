#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& obj);
	Intern& operator=(const Intern& obj);
	~Intern();
	AForm* makeForm(std::string name, std::string target);

	class FormNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	AForm* createShrubberyCreationForm(std::string const &target);
	AForm* createRobotomyRequestForm(std::string const &target);
	AForm* createPresidentialPardonForm(std::string const &target);
};


#endif
