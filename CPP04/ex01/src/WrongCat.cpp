#include "../include/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Wrong cat")
{
	this->name = "Wrong cat";
	std::cout << "Wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	this->name = copy.name;
	std::cout << "Copy contructor withing Wrong cat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "We all know wrong cats go to hell when they die. They hate it" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->name = other.name;
	}
	std::cout << "I'm wrong cat assigned." << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Moaw I'm a WrongCat" << std::endl;
}