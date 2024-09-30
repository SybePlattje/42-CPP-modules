#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	Animal* i = new Cat();
	const Animal* b = new Cat(*dynamic_cast<Cat*>(i));
	Animal* c = new Cat();
	*dynamic_cast<Cat*>(c) = dynamic_cast<Cat&>(*i);
	std::cout << "Before changeing the original" << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << b->getType() << std::endl;
	std::cout << c->getType() << std::endl;
	i->setType("Dog");
	std::cout << "After changeing the original" << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << b->getType() << std::endl;
	std::cout << c->getType() << std::endl;
	delete j;
	delete i;
	delete b;
	delete c;

	std::cout << std::endl;
	std::cout << std::endl;
	const Animal* a[4];
	for (int index = 0; index < 4; index++)
	{
		if (index % 2 == 0)
			a[index] = new Cat();
		else
			a[index] = new Dog();
		a[index]->makeSound();
		delete a[index];
	}
	return 0;
}