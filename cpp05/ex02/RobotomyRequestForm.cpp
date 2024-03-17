#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45) {
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	this->_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);
	std::cout << "Drilling noises" << std::endl;
	if (rand() % 2 == 0) {
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "Robotomization failed" << std::endl;
	}
}