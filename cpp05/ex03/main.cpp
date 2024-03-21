#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	// ShrubberyCreationForm: Required grades: sign 145, exec 137
	// RobotomyRequestForm: Required grades: sign 72, exec 45
	// PresidentialPardonForm: Required grades: sign 25, exec 5
	AForm *f1 = NULL;
	AForm *f2 = NULL;
	AForm *f3 = NULL;
	try {
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 40);
		Bureaucrat b3("b3", 100);
		Intern intern;
		f1 = intern.makeForm("shrubbery creation", "f1");
		f2 = intern.makeForm("robotomy request", "f2");
		f3 = intern.makeForm("presidential pardon", "f3");

		b1.signForm(*f1);
		b1.executeForm(*f1);

		b2.signForm(*f2);
		b2.executeForm(*f2);

		b3.signForm(*f3);
		b3.executeForm(*f3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	if (f1)
		delete f1;
	if (f2)
		delete f2;
	if (f3)
		delete f3;
	return 0;
}
