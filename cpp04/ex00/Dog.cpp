#include "Dog.hpp"

//OCCF
Dog::Dog(void) : Animal("Dog") {
	std::cout << "[OCCF] Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	std::cout << "[OCCF] Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "[OCCF] Dog assignation operator called" << std::endl;
	this->_type = obj._type;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "[OCCF] Dog destructor called" << std::endl;
}

//method
void Dog::makeSound(void) const {
	std::cout << "Dog say 'Bark Bark!'" << std::endl;
}
