#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5) {
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	this->_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}