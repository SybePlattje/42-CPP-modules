#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat: public WrongAnimal
{
	private:
		std::string name;
	public:
		WrongCat();
		WrongCat(const WrongCat&);
		~WrongCat();
		WrongCat& operator=(const WrongCat&);
		void makeSound() const;
};

#endif