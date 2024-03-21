#ifndef CPP_GIT_FORM_HPP
#define CPP_GIT_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	AForm(std::string const &name, int gradeToSign, int gradeToExecute);
	AForm(void);
	AForm(AForm const &src);
	AForm &operator=(AForm const &rhs);
	virtual ~AForm();

	std::string const &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	virtual void execute(Bureaucrat const &executor) const = 0;

	void beSigned();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormAlreadySignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
