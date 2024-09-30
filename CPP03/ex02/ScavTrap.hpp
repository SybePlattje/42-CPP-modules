#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
# endif

class ScavTrap : public ClapTrap
{
private:
	bool guarding;
public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(const ScavTrap&);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap&);
	void attack(const std::string&);
	void guardGate();
};


#endif