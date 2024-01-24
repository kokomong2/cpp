#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
 public:
	//OCCF
	Cure(void);
	Cure(const Cure& obj);
	Cure& operator=(const Cure& obj);
	~Cure(void);
	//method
	AMateria* clone(void) const;
	void use(ICharacter& target);
};

#endif
