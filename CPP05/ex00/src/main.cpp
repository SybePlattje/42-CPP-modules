#include "../include/Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat tim("tim", 44);
		std::cout << tim << std::endl;
		tim.decrementGrade();
		std::cout << tim << std::endl;
		tim.incrementGrade();
		std::cout << tim << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tim("tim", 1);
		std::cout << tim << std::endl;
		tim.incrementGrade();
		std::cout << tim << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tim("tim", 150);
		std::cout << tim << std::endl;
		tim.decrementGrade();
		std::cout << tim << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tim("tim", 200);
		std::cout << tim << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}