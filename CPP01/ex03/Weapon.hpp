#ifndef WEAPON_HPP
# define WEAPON_HPP

# ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
# endif

class Weapon
{
private:
	std::string type;
public:
	Weapon();
	Weapon(std::string);
	~Weapon();
	std::string getType() const;
	void setType(std::string);
};
#endif