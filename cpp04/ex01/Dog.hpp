#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

 private:
	Brain *_brain;
 public:
	//OCCF
	Dog(void);
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog(void);
	//method
	void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif