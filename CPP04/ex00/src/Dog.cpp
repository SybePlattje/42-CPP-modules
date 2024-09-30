#include "../include/Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	this->name = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	this->name = copy.name;
	std::cout << "Copy contructor withing Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dogs go to heaven, they are the best boys/girls." << std::endl; 
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->name = other.name;
	}
	std::cout << "I'm dog assigned." << std::endl;
	return *this;
}


void Dog::makeSound() const
{
	std::cout << "Bark I'm a dog!" << std::endl;
}