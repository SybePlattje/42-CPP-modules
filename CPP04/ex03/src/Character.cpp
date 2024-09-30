#include "../includes/Character.hpp"

Character::Character(): ICharacter()
{
	this->name = "me";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout<< "Character " << this->name << " created" << std::endl;
}

Character::Character(const Character& copy): ICharacter(copy)
{
	this->name = copy.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = copy.inventory[i]->clone();
	}
	std::cout << "Character copy constructor called" << std::endl;
}


Character::~Character()
{
	std::cout << "Character deconstructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
			this->inventory[i] = other.inventory[i]->clone();
		}
	}
	std::cout << "Character assign operator called" << std::endl;
	return *this;
}

const std::string& Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	int index = 0;
	while (index < 4)
	{
		if (this->inventory[index] == NULL)
		{
			this->inventory[index] = m;
			std::cout << this->name << " equiped " << m->getType() << std::endl;
			break;
		}
		index++;
	}
	if (index == 4)
	{
		std::cout << this->name << "'s inventory is full." << std::endl;
		std::cout << "You have to use or drop something before you can equip something new" << std::endl;
	}
}

void Character::unequip(int index)
{
	if (this->inventory[index] != NULL)
	{
		std::cout << this->name << " dropped " << this->inventory[index]->getType() << " item" << std::endl;
		this->inventory[index] = NULL;
	}
	else
		std::cout << "no item in that inventory slot" << std::endl;
}

void Character::use(int index, ICharacter& target)
{
	if ( this->inventory[index] != NULL)
	{
		this->inventory[index]->use(target);
		this->unequip(index);
	}
}
