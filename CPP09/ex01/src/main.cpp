#include "../include/RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Not the right amound of argumant given" << std::endl;
		return 1;
	}
	try
	{
		RPN calculator;
		int answer = calculator.parseInput(argv[1]);
		std::cout << "the answer is: " << answer << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
