#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

class Intern
{
	private:
		AForm* shrubberyForm(const std::string&);
		AForm* robotomyForm(const std::string&);
		AForm* presidentialForm(const std::string&);
	public:
		Intern();
		Intern(const Intern&);
		~Intern();
		Intern& operator=(const Intern&);
		AForm* makeForm(std::string, std::string);
};

#endif