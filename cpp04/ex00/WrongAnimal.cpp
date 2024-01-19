#include "WrongAnimal.hpp"

//OCCF
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << "[OCCF] WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "[OCCF] WrongAnimal name constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	std::cout << "[OCCF] WrongAnimal copy constructor called" << std::endl;
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	std::cout << "[OCCF] WrongAnimal assignation operator called" << std::endl;
	this->_type = obj._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "[OCCF] WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return (this->_type);
}

//method
void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal say nothing" << std::endl;
}
