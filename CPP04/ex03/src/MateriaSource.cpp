#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->firstMateria = true;
	for (int i = 0; i < 4; i++)
		this->knownMatera[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	this->firstMateria = copy.firstMateria;
	for (int i = 0; i < 4; i++)
	{
		if (copy.knownMatera[i] != NULL)
			this->knownMatera[i] = copy.knownMatera[i];
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		this->firstMateria = other.firstMateria;
		for (int i = 0; i < 4; i++)
		{
			if (other.knownMatera[i] != NULL)
				this->knownMatera[i] = other.knownMatera[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->knownMatera[i] != NULL)
			delete this->knownMatera[i];
	std::cout << "MateriaSource deconstructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (firstMateria)
	{
		this->knownMatera[0] = m;
		this->firstMateria = false;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->knownMatera[i] == NULL)
			{
				this->knownMatera[i] = m;
				break;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	AMateria* m = NULL;
	if (this->firstMateria)
	{
		std::cout << "No known meteria yet" << std::endl;
		return m;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->knownMatera[i] != NULL)
		{
			if (this->knownMatera[i]->getType().compare(type) == 0)
			{
				std::cout << "materia " << this->knownMatera[i]->getType() << " created" << std::endl;
				return this->knownMatera[i];
			}
		}
	}
	std::cout << "Trying to create a unknown materia" <<std::endl;
	return m;
}
