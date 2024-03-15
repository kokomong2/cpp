#ifndef CPP_GIT_FORM_HPP
#define CPP_GIT_FORM_HPP

#include <iostream>

class Form {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
	Form &operator=(Form const &rhs);

public:
	Form(std::string const &name, int gradeToSign, int gradeToExecute);
	Form(void);
	Form(Form const &src);
	~Form();

	std::string const &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

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

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
