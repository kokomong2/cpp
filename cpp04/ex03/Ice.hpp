#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
 public:
	//OCCF
	Ice(void);
	Ice(const Ice& obj);
	Ice& operator=(const Ice& obj);
	~Ice(void);
	//method
	AMateria* clone(void) const;
	void use(ICharacter& target);
};

#endif