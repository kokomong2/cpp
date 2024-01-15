#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	this->name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->name = obj.name;
	this->HitPoint = obj.HitPoint;
	this->EnergyPoint = obj.EnergyPoint;
	this->AttackDamage = obj.AttackDamage;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->HitPoint || !this->EnergyPoint)
	{
		std::cout << "ScavTrap " << this->name << " can't move" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " attack " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoint--;
	}
}
