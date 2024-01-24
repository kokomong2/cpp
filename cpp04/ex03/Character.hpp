#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
 private:
	std::string _name;
	AMateria*	_inventory[4];
	AMateria*	_floor[1000];
	int			_floorIndex;

 public:
	Character(void);
	Character(const std::string& name);
	Character(const Character& obj);
	Character& operator=(const Character& obj);
	~Character(void);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria* getInventory(int idx) const;
};

#endif