#include "../include/Span.hpp"
#include <iostream>
#include <limits>

int main()
{
	Span sp(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Span seederTest(100000);
		seederTest.seeder(3, 200000);
		std::vector<int> numbers = seederTest.getNumbers();
		for (unsigned int i = 0; i < seederTest.getSize(); i++)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;
		std::cout << seederTest.shortestSpan() << std::endl;
		std::cout << seederTest.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Span span(3);
		span.addNumber(4);
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Span span(3);
		span.addNumber(4);
		span.addNumber(55);
		span.addNumber(88);
		span.addNumber(12568);
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span span(2);
		span.addNumber(INT32_MIN);
		span.addNumber(INT32_MAX);
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}
