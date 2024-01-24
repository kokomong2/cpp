#include "Ice.hpp"

// CONSTRUCTOR / DESTRUCTOR
Ice::Ice(void) : AMateria("ice") {
	std::cout << "[OCCF] Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& obj) : AMateria(obj) {
	std::cout << "[OCCF] Ice copy constructor called" << std::endl;
	*this = obj;
}

Ice::~Ice(void) {
	std::cout << "[OCCF] Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& obj) {
	std::cout << "[OCCF] Ice assignation operator called" << std::endl;
	this->_type = obj._type;
	return (*this);
}

// MEMBER FUNCTIONS

AMateria* Ice::clone(void) const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}
