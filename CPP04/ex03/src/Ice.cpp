#include "../includes/Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	this->name = "ice";
	std::cout << "ice constructor called" << std::endl;
}

Ice::Ice(const Ice& copy): AMateria(copy.name)
{
	this->name = copy.name;
	std::cout << "ice copy constructor called" << std::endl;
}

Ice::Ice(std::string name): AMateria(name)
{
	this->name = name;
	std::cout << "ice " << this->name << " constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "ice deconstructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		this->name = other.name;
	}
	std::cout << "ice assign operator called" << std::endl;
	return *this;
}

AMateria* Ice::clone() const
{
	AMateria* clone = new Ice();
	std::cout << this->name << " cloned" <<std::endl;
	return clone;
}
