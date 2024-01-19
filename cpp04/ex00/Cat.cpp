#include "Cat.hpp"

//OCCF
Cat::Cat(void) : Animal("Cat") {
	std::cout << "[OCCF] Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj) {
	std::cout << "[OCCF] Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "[OCCF] Cat assignation operator called" << std::endl;
	this->_type = obj._type;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "[OCCF] Cat destructor called" << std::endl;
}

//method
void Cat::makeSound(void) const {
	std::cout << "Cat say 'Meow Meow!'" << std::endl;
}
