#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), FragTrap("default_clap_name"), ScavTrap("default_clap_name")
{
	this->name = "default";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << this->name << " is a diamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << this->name << " at your service" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	*this = copy;
	std::cout << "a new shiny me" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->name << " Is grinded to dust" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		ClapTrap(other.name + "clap_name");
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "DiamondTrap " << this->name << " at your service" << std::endl;
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Hi I'm " << this->name << " my ClapTrap name is " << ClapTrap::name << std::endl;
}