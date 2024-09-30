#ifndef IMATERIASOURCE
# define IMATERIASOURCE

# include "AMateria.hpp"

# include <iostream>

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif