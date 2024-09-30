#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (i > 1)
				std::cout << " ";
			std::string input = argv[i];
			for (unsigned long j = 0; j < input.length(); j++)
				input[j] = std::toupper(input[j]);
			std::cout << input;
		}
		std::cout << std::endl;
	}
	return 0;
}
