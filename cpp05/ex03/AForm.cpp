#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _gradeToSign(150), _gradeToExecute(150) {
	this->_isSigned = false;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
	this->_isSigned = false;
}

AForm::AForm(AForm const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
	*this = src;
}

AForm::~AForm() {
}

AForm &AForm::operator=(AForm const &other) {
	if (this != &other){
		const_cast<std::string&>(_name) = other._name;
		_isSigned = other._isSigned;
		const_cast<int&>(_gradeToSign) = other._gradeToSign;
		const_cast<int&>(_gradeToExecute) = other._gradeToExecute;
	}
	return (*this);
}

std::string const &AForm::getName() const {
	return (this->_name);
}

bool AForm::getSigned() const {
	return (this->_isSigned);
}

int AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void AForm::beSigned() {
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->_isSigned) {
		throw AForm::FormNotSignedException();
	} else if (executor.getGrade() > this->_gradeToExecute) {
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return ("Form is already signed");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << f.getName()
		<< std::boolalpha <<", signed : " << f.getSigned()
		<< ", signGrade : " << f.getGradeToSign()
		<< ", execGrade : " << f.getGradeToExecute();
	return (out);
}
