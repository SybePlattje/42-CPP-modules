#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
# include <iostream>

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* knownMatera[4];
		bool firstMateria;
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource&);
		void learnMateria(AMateria*);
		AMateria* createMateria(const std::string&);
};

#endif