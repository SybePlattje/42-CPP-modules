#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat: public Animal
{
	private:
		std::string name;
		Brain* brain;
	public:
		Cat();
		Cat(const Cat&);
		virtual ~Cat();
		Cat& operator=(const Cat&);
		void makeSound() const;
};

#endif