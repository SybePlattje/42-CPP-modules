#include "../includes/Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	this->name = "cure";
	std::cout << "cure constructor called" << std::endl;
}


Cure::Cure(const Cure& copy): AMateria(copy)
{
	this->name = copy.name;
	std::cout << "cure  copy constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "cure deconstructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		this->name = other.name;
	}
	std::cout << "cure assign operator called" << std::endl;
	return *this;
}

AMateria* Cure::clone() const
{
	AMateria* clone = new Cure();
	std::cout << this->name << " clonded" << std::endl;
	return clone;
}
