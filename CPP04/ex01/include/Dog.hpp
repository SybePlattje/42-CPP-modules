#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog: public Animal
{
	private:
		std::string name;
		Brain* brain;
	public:
		Dog();
		Dog(const Dog&);
		virtual ~Dog();
		Dog& operator=(const Dog&);
		void makeSound() const;
};

#endif