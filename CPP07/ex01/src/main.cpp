#include "../include/iter.hpp"
#include <iostream>

template<typename T>
void tPrint(T& input)
{
	std::cout << input << std::endl;
}

void print(std::string input)
{
	iter(&input[0], input.size(), &tPrint);
	std::cout << std::endl;
}

int main()
{
	int values[] = {4, 5, 2, 3};
	std::string strings[] = {"hello", "lets", "print", "this"};

	iter(&values[0], 4, tPrint);
	iter(&strings[0], 4, tPrint);
	iter(&strings[0], 4, print);
}
