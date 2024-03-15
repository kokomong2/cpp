#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {

	try
	{
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		Form f("f", 100, 100);
		std::cout << f << std::endl;

		a.signForm(f);
		std::cout << f << std::endl;

		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
