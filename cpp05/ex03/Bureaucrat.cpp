
#include "Bureaucrat.hpp"

//OCCF
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs) {
		this->_grade = rhs._grade;
	}
	return (*this);
}

std::string const &Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		if (form.getSigned()) {
			throw AForm::FormAlreadySignedException();
		} else if (this->_grade > form.getGradeToSign()) {
			throw AForm::GradeTooLowException();
		}
		std::cout << this->_name << " signed " << form.getName() << std::endl;
		form.beSigned();
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}

void Bureaucrat::executeForm(AForm const &form) const {
	try {
		std::cout << this->_name << " executes " << form.getName() << std::endl;
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}