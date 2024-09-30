#include "../include/Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat tim("tim", 80);
		std::cout << tim << std::endl;
		Form test("test", 70, 50);
		std::cout << test << std::endl;
		tim.signForm(test);
		std::cout << test << std::endl;
		for (int i = 0; i < 10; i++)
			tim.incrementGrade();
		std::cout << tim << std::endl;
		tim.signForm(test);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}