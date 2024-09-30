#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->name = "ScavTrap";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->guarding = false;
	std::cout << "Well I'm a ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->guarding = false;
	std::cout << "My name is " << this->name << " and I'm a ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy)
{
	this->guarding = copy.guarding;
	std::cout << "There are more of me" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "Scavtrap " << this->name << " at your service" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Is that the sun? Shit go back, go back" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
		std::cout << this->name << " is gone" << std::endl;
	else if (energyPoints == 0)
		std::cout << this->name << " is out of juice" << std::endl;
	else
	{
		this->energyPoints--;
		std::cout << "ScavTrap " << this->name << " attacks " << target 
			<< ", causing " << this->attackDamage << " points of damage" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (guarding)
		std::cout << name << " is now in guard mode." << std::endl;
	else
		std::cout << name << " is already in guard mode" << std::endl;
}