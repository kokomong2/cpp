#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("default"), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = obj.name;
	this->HitPoint = obj.HitPoint;
	this->EnergyPoint = obj.EnergyPoint;
	this->AttackDamage = obj.AttackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

unsigned int ClapTrap::getDamege(void) const
{
	return (this->AttackDamage);
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->HitPoint || !this->EnergyPoint)
	{
		std::cout << "ClapTrap " << this->name << " can't move" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->HitPoint)
		this->HitPoint = 0;
	else
		this->HitPoint -= amount;
	std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
	if (!this->HitPoint)
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->HitPoint || !this->EnergyPoint)
	{
		std::cout << "ClapTrap " << this->name << " can't move" << std::endl;
		return ;
	}
	if (this-> HitPoint + amount > 10)
	{
		std::cout << "ClapTrap " << this->name << " be repaired " << 10 - this->HitPoint << " points of damage!" << std::endl;
		this->HitPoint = 10;
	}
	else
	{
		this->HitPoint += amount;
		this->EnergyPoint--;
		std::cout << "ClapTrap " << this->name << " be repaired " << amount << " points of damage!" << std::endl;
	}
}
