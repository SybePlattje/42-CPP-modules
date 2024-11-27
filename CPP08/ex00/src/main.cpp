#include "../include/Easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found element: " << *it << " in vector." << std::endl;
	} 
	catch (const ElementNotFoundException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Found element: " << *it << " in vector." << std::endl;
	}
	catch (const ElementNotFoundException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << "Found element: " << *it << " in list." << std::endl;
	}
	catch (const ElementNotFoundException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(lst, 60);
		std::cout << "Found element: " << *it << " in list." << std::endl;
	}
	catch (const ElementNotFoundException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}