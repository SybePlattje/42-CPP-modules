#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string);
		Animal(const Animal&);
		virtual ~Animal();
		Animal& operator=(const Animal&);
		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string);
};

#endif