#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
	//OCCF
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& obj);
	ScavTrap& operator=(const ScavTrap& obj);
	~ScavTrap(void);
	//method
	void guardGate(void);
	void attack(const std::string &target);
};

#endif