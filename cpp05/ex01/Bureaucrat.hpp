#ifndef CPP_GIT_BUREAUCRAT_HPP
#define CPP_GIT_BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
	Bureaucrat &operator=(Bureaucrat const &rhs);

public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	std::string const &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
