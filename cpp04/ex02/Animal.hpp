#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
 protected:
	std::string _type;
 public:
	//OCCF
	Animal(void);
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);
	virtual ~Animal(void);
	//method
	std::string getType(void) const;
	virtual void makeSound(void) const = 0;
};

#endif