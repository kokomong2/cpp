#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void foo(void)
{
	system("leaks ex00");
}

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrong = new WrongCat();

	// atexit(foo);
	std::cout << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	std::cout << std::endl;
	delete meta;
	meta = NULL;
	delete dog;
	dog = NULL;
	delete cat;
	cat = NULL;
	delete wrong;
	wrong = NULL;
	return 0;
}
