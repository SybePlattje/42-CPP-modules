#include "../include/Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain())
{
	this->name = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	this->name = copy.name;
	this->brain = new Brain(*(copy.brain));
	std::cout << "Copy constructor withing Cat" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "We all know cats go to hell when they die. They love it" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->name = other.name;
		delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	std::cout << "I'm cat assigned." << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Moaw I'm a cat!" << std::endl;
}