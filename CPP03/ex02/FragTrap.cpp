#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->name = "FragTrap";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "Well I'm a FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "My name is " << this->name << " and I'm a FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	std::cout << "Hopefully it't a friend" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "FragTrap " << this->name << " at your service" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << this->name << " explodes!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << this->name << " is standing with its hands up waiting for someone to high-five with." << std::endl;
	std::cout << "Nobody responded, now " << this->name << " is sad" << std::endl;
}