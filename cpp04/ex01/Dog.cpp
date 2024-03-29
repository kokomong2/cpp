#include "Dog.hpp"

//OCCF
Dog::Dog(void) : Animal() {
	std::cout << "[OCCF] Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal() {
	std::cout << "[OCCF] Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "[OCCF] Dog assignation operator called" << std::endl;
	*this->_brain = *obj._brain;
	this->_type = obj._type;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "[OCCF] Dog destructor called" << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}

//method
void Dog::makeSound(void) const {
	std::cout << "Dog say 'Bark Bark!'" << std::endl;
}

Brain* Dog::getBrain(void) const {
	return (this->_brain);
}
