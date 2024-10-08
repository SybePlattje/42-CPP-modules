#include "../include/Array.hpp"
#include <iostream>

int main()
{
	try 
	{
		Array<int>ar;
		Array<int> intArray(5);
		for (unsigned int i = 0; i < intArray.Size(); ++i)
			intArray[i] = static_cast<int>(i) * 10;
		for (unsigned int i = 0; i < intArray.Size(); ++i)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;
		Array<int> copyArray(intArray);
		for (unsigned int i = 0; i < copyArray.Size(); ++i)
			std::cout << copyArray[i] << " ";
		std::cout << std::endl;
		std::cout << intArray[8] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
