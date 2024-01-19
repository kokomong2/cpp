#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
 protected:
	std::string _type;
 public:
	//OCCF
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& obj);
	WrongAnimal& operator=(const WrongAnimal& obj);
	virtual ~WrongAnimal(void);
	//method
	std::string getType(void) const;
	void makeSound(void) const;
};

#endif