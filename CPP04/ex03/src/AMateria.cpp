#include "../includes/AMateria.hpp"

AMateria::AMateria()
{
	this->type = "materia";
	std::cout << "AMateria constroctor called" << std::endl;
}

AMateria::AMateria(const std::string& type)
{
	this->type = type;
	std::cout << "AMateria " << this->type << " constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	this->type = copy.type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "AMateria copy assign operator called" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria deconstructor called" << std::endl;
}

const std::string& AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	if (this->type.compare("ice") == 0)
		std::cout << "Shoots an ice bolt at " << target.getName() << std::endl;
	else if (this->type.compare("cure") == 0)
		std::cout << "Heals " << target.getName() << "'s wounds" << std::endl;
	else
		std::cout << std::endl;
}
