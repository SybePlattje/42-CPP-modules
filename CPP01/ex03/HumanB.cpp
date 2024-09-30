#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon *weapon)
{
	this->name = name;
	this->weapon = weapon;
}
HumanB::~HumanB(){};

void HumanB::attack()
{
	if (weapon == NULL)
		std::cout << this->name << " attacks with their " << "Bloody fists" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}