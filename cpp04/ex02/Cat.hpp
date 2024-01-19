#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
 private:
	Brain* _brain;
 public:
	//OCCF
	Cat(void);
	Cat(const Cat& obj);
	Cat& operator=(const Cat& obj);
	~Cat(void);
	//method
	void makeSound(void) const;
	Brain* getBrain(void) const;
};

#endif