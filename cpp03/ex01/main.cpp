#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("A");
	ScavTrap b("B");

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("A");
	b.takeDamage(8);
	a.takeDamage(10);
	a.beRepaired(10);
	return (0);
}