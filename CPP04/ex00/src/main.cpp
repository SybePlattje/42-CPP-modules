#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Dog* dog = new Dog();
	const Cat* cat = new Cat();
	const WrongAnimal* animal = new WrongAnimal();
	const WrongCat* wrongCat = new WrongCat();

	std::cout << "meta's type is " << meta->getType() << " " << std::endl;
	std::cout << "j's type is " << j->getType() << " " << std::endl;
	std::cout << "i't type is " << i->getType() << " " << std::endl;
	std::cout << "Cat's type is " << cat->getType() << " " << std::endl;
	std::cout << "Dog's type is " << dog->getType() << " " << std::endl;
	std::cout << "animal's type is " << animal->getType() << " " << std::endl;
	std::cout << "wrongCat's type is " << wrongCat->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	wrongCat->makeSound();

	delete meta;
	delete i;
	delete j;
	delete cat;
	delete dog;
	delete animal;
	delete wrongCat;
}