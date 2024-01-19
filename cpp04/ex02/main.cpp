#include "Dog.hpp"
#include "Cat.hpp"

void	foo(void)
{
	system("leaks ex01");
}

int main()
{
	std::string str;
	Animal *meta[10];

	// atexit(foo);
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Dog();
		}
		else
		{
			meta[i] = new Cat();
		}
	}
	std::cout << std::endl;
	
	for (size_t i = 0; i < 10; i++)
	{
		delete meta[i];
	}
	std::cout << std::endl;
	

	Dog *d = new Dog();
	Dog *d2 = new Dog();
	std::cout << std::endl;
	str = d->getBrain()->getIdea(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	d->getBrain()->setIdea(0, "something");
	str = d->getBrain()->getIdea(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdea(0);
	std::cout << "Dog2's first idea is "<< str << std::endl;

	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;

	return 0;
}