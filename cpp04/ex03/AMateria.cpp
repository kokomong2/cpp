#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default") {
	std::cout << "[OCCF] AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << "[OCCF] AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj) {
	std::cout << "[OCCF] AMateria copy constructor called" << std::endl;
	*this = obj;
}

AMateria::~AMateria(void) {
	std::cout << "[OCCF] AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& obj) {
	std::cout << "[OCCF] AMateria assignation operator called" << std::endl;
	this->_type = obj._type;
	return (*this);
}

std::string const& AMateria::getType(void) const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
