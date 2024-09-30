#ifndef CURE
# define CURE

# include "AMateria.hpp"
# include<iostream>

class Cure: public AMateria
{
	private:
		std::string name;
	public:
		Cure();
		Cure(std::string name);
		Cure(const Cure&);
		~Cure();
		Cure& operator=(const Cure&);
		AMateria* clone() const;
};

#endif