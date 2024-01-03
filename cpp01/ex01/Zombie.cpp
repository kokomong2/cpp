#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "default";
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead" << std::endl;
}

void	Zombie::announce()
{
	std::cout << "" << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

