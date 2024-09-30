#ifndef ICE
# define ICE

# include "AMateria.hpp"
# include <iostream>

class Ice: public AMateria
{
	private:
		std::string name;
	public:
	Ice();
	Ice(std::string);
	Ice(const Ice&);
	~Ice();
	Ice& operator=(const Ice&);
	AMateria* clone() const;
};

#endif