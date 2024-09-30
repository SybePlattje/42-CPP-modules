#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
# endif

class ClapTrap
{
protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string);
	ClapTrap(const ClapTrap&);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap&);
	void attack(const std::string&);
	void takeDamage(unsigned int);
	void beRepaired(unsigned int);
};

#endif