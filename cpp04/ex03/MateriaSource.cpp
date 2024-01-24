#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	std::cout << "[OCCF] MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj) {
	std::cout << "[OCCF] MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = obj._materia[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
	std::cout << "[OCCF] MateriaSource assignation operator called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = obj._materia[i];
	return (*this);
}

MateriaSource::~MateriaSource(void) {
	std::cout << "[OCCF] MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_materia[i];
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] == NULL) {
			this->_materia[i] = materia;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (NULL);
}
