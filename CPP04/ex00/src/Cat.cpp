#include "../include/Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	this->name = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	this->name = copy.name;
	std::cout << "Copy constructor withing Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "We all know cats go to hell when they die. They love it" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->name = other.name;
	}
	std::cout << "I'm cat assigned." << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Maow I'm a cat!" << std::endl;
}