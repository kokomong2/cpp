#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : _name("default"), _inventory() {
	std::cout << "[OCCF] Character default constructor called" << std::endl;
	this->_floorIndex = 0;
}

Character::Character(const std::string& name) : _name(name), _inventory() {
	std::cout << "[OCCF] Character name constructor called" << std::endl;
	this->_floorIndex = 0;
}

Character::Character(const Character& obj) : _name(obj._name), _inventory() {
	std::cout << "[OCCF] Character copy constructor called" << std::endl;
	*this = obj;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	for (int i = 0; i < 1000; i++){
		if (this->_floor[i] != NULL)
			delete this->_floor[i];
	}
	std::cout << "[OCCF] Character destructor called" << std::endl;
}

Character& Character::operator=(const Character& obj) {
	std::cout << "[OCCF] Character assignation operator called" << std::endl;
	this->_name = obj._name;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = obj._inventory[i]->clone();
	}
	for (int i = 0; i < 1000; i++){
		if (this->_floor[i] != NULL)
			delete this->_floor[i];
		this->_floor[i] = obj._floor[i]->clone();
	}
	this->_floorIndex = obj._floorIndex;
	return (*this);
}

std::string const & Character::getName(void) const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m->clone();
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
		return ;
	if (this->_floorIndex >= 1000)
		return ;
	this->_floor[this->_floorIndex] = this->_inventory[idx];
	this->_floorIndex++;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL){
		std::cout << "No materia in this slot" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

AMateria* Character::getInventory(int idx) const {
	if (idx < 0 || idx > 3)
		return (NULL);
	return (this->_inventory[idx]);
}

std::ostream& operator<<(std::ostream& os, const Character& obj) {
	os << obj.getName() << " has the following materia:" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (obj.getInventory(i) != NULL)
			os << " - " << obj.getInventory(i)->getType() << std::endl;
	}
	return (os);
}
