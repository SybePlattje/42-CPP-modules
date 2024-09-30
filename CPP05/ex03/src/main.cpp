#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"

int main()
{
	Intern intern;
	Bureaucrat tom("Tom", 110);
	try
	{
		AForm* form = intern.makeForm("Shrubbery Creation", "Home");
		tom.signForm(*form);
		if (!form->execute(tom))
			std::cout<< tom.getName() << " can execute " << form->getName() << std::endl;
		delete form;
	}
	catch (std::exception e)
	{
		e.what();
	}
	try
	{
		AForm* form = intern.makeForm("Test Form", "test");
		if (form != nullptr)
		{
			tom.signForm(*form);
			if (!form->execute(tom))
				std::cout<< tom.getName() << " can execute " << form->getName() << std::endl;
			delete form;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
