#include "../include/Animal.hpp"

Animal::Animal()
{
	this->type = "An animal";
	std::cout << this->type << " is born." << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "named constructor for " << this->type << " called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	this->type = copy.type;
	std::cout << "I am an animal copy of " << this->type << std::endl;
}

Animal::~Animal()
{
	std::cout << "The animal has been layed to rest." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "I'm animal assigned." << std::endl;
	return *this;
}

void Animal::makeSound() const
{
		std::cout << "Strange animal sounds." << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}