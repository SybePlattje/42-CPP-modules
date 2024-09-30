#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "ClapTrap";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "I'M ALIIIVE!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << this->name << " at your service!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	std::cout << name << " has made a copy of it self. HA.. HA.. HAHAHAHA!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "It's finally over...I see a bright light...it's beautiful...beautiful..." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	std::cout << "Hi " << name << "is ready" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
		std::cout << this->name << " is dead!" << std::endl;
	else if (energyPoints == 0)
		std::cout << this->name << " has no energy left" << std::endl;
	else
	{
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " attacks " << target 
			<< ", causing " << this->attackDamage << " points of damage" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
		std::cout << this->name << " is alread dead" << std::endl;
	else if (amount > this->hitPoints)
	{
		std::cout << "Overkill!" <<std::endl;
		this->hitPoints = 0;
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "Help me minion!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
		std::cout << this->name << " is dead!" << std::endl;
	else if (this->energyPoints == 0)
		std::cout << this->name << " has no energy left" << std::endl;
	else if (this->hitPoints >= 10)
		std::cout << this->name << " I'm already at max hit points" << std::endl;
	else
	{
		this->energyPoints--;
		this->hitPoints += amount;
		std::cout << "That's better! Luckely " << this->name << " can repair it self." << std::endl;
	}
}
