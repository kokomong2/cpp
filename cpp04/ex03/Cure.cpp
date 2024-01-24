#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "[OCCF] Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria(obj) {
	std::cout << "[OCCF] Cure copy constructor called" << std::endl;
	*this = obj;
}

Cure::~Cure(void) {
	std::cout << "[OCCF] Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& obj) {
	std::cout << "[OCCF] Cure assignation operator called" << std::endl;
	this->_type = obj._type;
	return (*this);
}

AMateria* Cure::clone(void) const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}
