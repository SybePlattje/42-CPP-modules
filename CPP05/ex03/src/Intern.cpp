#include "../include/Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern::~Intern() {};

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		*this = other;
	return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string names[3] = {"Shrubbery Creation", "Robotics Request", "Presidential Pardon" };
	typedef AForm* (Intern::*formCreationFunction)(const std::string&);
	formCreationFunction formSelectFunction[3] = 
	{
		&Intern::shrubberyForm,
		&Intern::robotomyForm,
		&Intern::presidentialForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(names[i]) == 0)
		{
			AForm* form = (this->*formSelectFunction[i])(target);
			std::cout << "Intern created form: " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "The file you tried to make doesn't exist" << std::endl;
	return nullptr;
}

// private

AForm* Intern::shrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::robotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::presidentialForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}