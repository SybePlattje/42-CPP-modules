#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include <iostream>

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
	public:
		Character();
		Character(std::string);
		Character(const Character&);
		~Character();
		Character& operator=(const Character&);
		const std::string& getName() const;
		void equip(AMateria*);
		void unequip(int);
		void use(int, ICharacter&);
};

#endif