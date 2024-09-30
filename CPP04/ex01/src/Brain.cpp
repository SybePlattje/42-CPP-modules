#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain has been made" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	std::cout << "Brain has been copied" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain has been killed" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brains assign operator called" << std::endl;
	return *this;
}
