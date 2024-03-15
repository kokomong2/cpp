#include "AForm.hpp"

Form::Form(void) : _name("default"), _gradeToSign(150), _gradeToExecute(150) {
	this->_isSigned = false;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw Form::GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw Form::GradeTooLowException();
	}
	this->_isSigned = false;
}

Form::Form(Form const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
	*this = src;
}

Form::~Form() {
}

Form &Form::operator=(Form const &rhs) {
	this->_isSigned = rhs._isSigned;
	return (*this);
}

std::string const &Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_isSigned);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void Form::beSigned() {
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char *Form::FormAlreadySignedException::what() const throw() {
	return ("Form is already signed");
}

const char *Form::FormNotSignedException::what() const throw() {
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << f.getName()
		<< std::boolalpha <<", signed : " << f.getSigned()
		<< ", signGrade : " << f.getGradeToSign()
		<< ", execGrade : " << f.getGradeToExecute();
	return (out);
}
