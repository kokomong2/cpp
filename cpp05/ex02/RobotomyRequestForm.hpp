#ifndef CPP_GIT_ROBOTOMYREQUESTFORM_HPP
#define CPP_GIT_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm{
private:
	RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	std::string _target;

public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const &executor) const;
};

#endif
