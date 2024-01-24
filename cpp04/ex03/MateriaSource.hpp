#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
	AMateria* _materia[4];
 public:
	//OCCF
	MateriaSource(void);
	MateriaSource(const MateriaSource& obj);
	MateriaSource& operator=(const MateriaSource& obj);
	virtual ~MateriaSource(void);
	//method
	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);
};

#endif
