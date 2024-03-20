#ifndef CPP_GIT_PRESIDENTIALPARDONFORM_HPP
#define CPP_GIT_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm{

private:
	PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	std::string _target;

public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const &executor) const;
};


#endif
