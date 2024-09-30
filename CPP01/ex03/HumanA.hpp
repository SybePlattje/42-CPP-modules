#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
# endif

class HumanA
{
private:
	Weapon &weapon;
	std::string name;
public:
	HumanA(std::string, Weapon&);
	~HumanA();
	void attack();
};


#endif