#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	// ShrubberyCreationForm: Required grades: sign 145, exec 137
	// RobotomyRequestForm: Required grades: sign 72, exec 45
	// PresidentialPardonForm: Required grades: sign 25, exec 5
	try {
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);
		Bureaucrat b3("b3", 100);
		AForm *f1 = new ShrubberyCreationForm("f1");
		AForm *f2 = new RobotomyRequestForm("f2");
		AForm *f3 = new PresidentialPardonForm("f3");

		b1.signForm(*f1);
		b1.executeForm(*f1);

		b2.signForm(*f2);
		b2.executeForm(*f2);

		b3.signForm(*f3);
		b3.executeForm(*f3);

		delete f1;
		delete f2;
		delete f3;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
