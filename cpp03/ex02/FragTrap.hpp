#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
	//OCCF
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap& obj);
	FragTrap& operator=(const FragTrap& obj);
	virtual ~FragTrap(void);
	//method
	void highFivesGuys(void);
};

#endif