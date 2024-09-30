#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	//const Animal animal = new Animal();

	const Dog* j = new Dog();
	Cat* i = new Cat();
	const Cat* b = new Cat(*dynamic_cast<Cat*>(i));
	Cat* c = new Cat();
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
	return 0;
}