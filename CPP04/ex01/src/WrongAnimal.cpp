#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "An animal";
	std::cout << this->type << " is born." << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
{
	this->type = name;
	std::cout << this->type << " is born." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	this->type = copy.type;
	std::cout << "I am an wrong animal copy of " << this->type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "The wrong animal has been layed to rest." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "I'm wrong animal assigned." << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Strange wrong animal sounds." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}