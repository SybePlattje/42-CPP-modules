#include "../include/Dog.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain())
{
	this->name = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	this->name = copy.name;
	this->brain = new Brain(*(copy.brain));
	std::cout << "Copy constructor withing Dog" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dogs go to heaven, they are the best boys/girls." << std::endl; 
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->name = other.name;
		delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	std::cout << "I'm dog assigned." << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woef, I'm a dog" << std::endl;
}