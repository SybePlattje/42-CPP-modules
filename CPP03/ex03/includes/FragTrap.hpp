#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# ifndef IOSTREAM
#  define IOSTREAM
#  include <iostream>
# endif

class FragTrap: virtual public ClapTrap
{
	private:
	public:
		FragTrap();
		FragTrap(std::string);
		FragTrap(const FragTrap&);
		~FragTrap();
		FragTrap& operator=(const FragTrap&);
		void highFivesGuys();
};

#endif