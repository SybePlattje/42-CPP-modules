#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
# endif

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB(std::string, Weapon *Weapon = NULL);
	~HumanB();
	void attack();
	void setWeapon(Weapon*);
};
#endif