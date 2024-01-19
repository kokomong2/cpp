#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "[OCCF] Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& obj) {
	std::cout << "[OCCF] Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj) {
	std::cout << "[OCCF] Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = obj._ideas[i];
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "[OCCF] Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
	return (this->_ideas[index]);
}

void Brain::setIdea(int index, std::string idea) {
	this->_ideas[index] = idea;
}
