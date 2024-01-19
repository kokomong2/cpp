#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
	std::cout << "[OCCF] Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) {
	std::cout << "[OCCF] Animal copy constructor called" << std::endl;
	*this = obj;
}

Animal& Animal::operator=(const Animal& obj) {
	std::cout << "[OCCF] Animal assignation operator called" << std::endl;
	this->_type = obj._type;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "[OCCF] Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const {
	return (this->_type);
}

void Animal::makeSound(void) const {
	std::cout << "Animal say nothing" << std::endl;
}
