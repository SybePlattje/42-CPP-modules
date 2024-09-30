#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "not the right amound of argumants" << std::endl;
		return 1;
	}
	std::string myString(argv[1]);
	ScalarConverter::convert(myString);
}
