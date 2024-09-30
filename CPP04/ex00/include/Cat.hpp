#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat: public Animal
{
	private:
		std::string name;
	public:
		Cat();
		Cat(const Cat&);
		~Cat();
		Cat& operator=(const Cat&);
		void makeSound() const;

};

#endif