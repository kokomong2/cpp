#ifndef CPP_GIT_SHRUBBERYCREATIONFORM_HPP
#define CPP_GIT_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
private:
	ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	std::string _target;

public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	virtual ~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const &executor) const;
};


#endif