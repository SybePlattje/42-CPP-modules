#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"

int main()
{
	std::cout << "------shrubberyCrationForm-----------" << std::endl;
	try
	{
		Bureaucrat tom = Bureaucrat("Tom", 140);
		ShrubberyCreationForm shrub("home");
		if (!tom.executeForm(shrub))
			shrub.createShrubbery();
		tom.signForm(shrub);
		if (!tom.executeForm(shrub))
			shrub.createShrubbery();
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << '\n';
	try 
	{
		Bureaucrat tom = Bureaucrat("Tom", 135);
		ShrubberyCreationForm shrub("home");
		tom.signForm(shrub);
		if (!tom.executeForm(shrub))
			shrub.createShrubbery();
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << '\n';
	std::cout << "------robotomyRequestForm-----------" << std::endl;
	try 
	{
		Bureaucrat tom = Bureaucrat("Tom", 55);
		RobotomyRequestForm robot(tom.getName());
		if (!tom.executeForm(robot))
			robot.doRobotics();
		tom.signForm(robot);
		if (!tom.executeForm(robot))
			robot.doRobotics();
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << '\n';
	try 
	{
		Bureaucrat tom = Bureaucrat("Tom", 40);
		RobotomyRequestForm robot(tom.getName());
		tom.signForm(robot);
		if (!tom.executeForm(robot))
			robot.doRobotics();
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << '\n';
	std::cout << "------presidentialPardonForm-----------" << std::endl;
	try 
	{
		Bureaucrat tom = Bureaucrat("Tom", 20);
		PresidentialPardonForm ppf(tom.getName());
		if (!tom.executeForm(ppf))
			ppf.pardon();
		tom.signForm(ppf);
		if (!tom.executeForm(ppf))
			ppf.pardon();
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << '\n';
	try 
	{
		Bureaucrat tom = Bureaucrat("Tom", 2);
		PresidentialPardonForm ppf(tom.getName());
		tom.signForm(ppf);
		if (!tom.executeForm(ppf))
			ppf.pardon();
	} catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}