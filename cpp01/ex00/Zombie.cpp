#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "default";
}

Zombie::Zombie(std::string name)
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

