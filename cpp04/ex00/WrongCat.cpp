#include "WrongCat.hpp"

//OCCF
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "[OCCF] WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj) {
	std::cout << "[OCCF] WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
	std::cout << "[OCCF] WrongCat assignation operator called" << std::endl;
	this->_type = obj._type;
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "[OCCF] WrongCat destructor called" << std::endl;
}

//method
void WrongCat::makeSound(void) const {
	std::cout << "WrongCat say 'Wrong Wrong!'" << std::endl;
}
