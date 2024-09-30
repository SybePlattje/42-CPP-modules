#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
# endif

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string);
		DiamondTrap(const DiamondTrap&);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap&);
		void attack(const std::string&);
		void whoAmI();
};

#endif