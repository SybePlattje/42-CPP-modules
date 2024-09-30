#ifndef AMATERIA
# define AMATERIA

# include "ICharacter.hpp"
# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string type;
		AMateria();

	public:
		AMateria(const AMateria&);
		AMateria& operator=(const AMateria&);
		AMateria(const std::string&);
		virtual ~AMateria();
		const std::string& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter&);
};

#endif