#include "Cat.hpp"

//OCCF
Cat::Cat(void) : Animal() {
	std::cout << "[OCCF] Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& obj) : Animal() {
	std::cout << "[OCCF] Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "[OCCF] Cat assignation operator called" << std::endl;
	*this->_brain = *obj._brain;
	this->_type = obj._type;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "[OCCF] Cat destructor called" << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}

//method
void Cat::makeSound(void) const {
	std::cout << "Cat say 'Meow Meow!'" << std::endl;
}

Brain* Cat::getBrain(void) const {
	return (this->_brain);
}
