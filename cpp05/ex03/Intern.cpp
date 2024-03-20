#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &obj) {
	*this = obj;
}


Intern &Intern::operator=(const Intern &obj) {
	(void)obj;
	return (*this);
}

Intern::~Intern() {
}

AForm *Intern::makeForm(std::string name, std::string target) {
	const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *form = NULL;
	AForm *(Intern::*formCreate[3])(std::string const &target) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			form = (this->*formCreate[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	if (form == NULL) {
		throw Intern::FormNotFoundException();
	}
	return (form);
}

AForm *Intern::createShrubberyCreationForm(std::string const &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) {
	return (new PresidentialPardonForm(target));
}

const char *Intern::FormNotFoundException::what() const throw() {
	return ("AForm not found");
}
