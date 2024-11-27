#include "../include/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;

	mstack.pop();

	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(55);
	mstack.push(22);
	mstack.push(1265698);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "list output" << std::endl;

	std::list<int> list;
	list.push_front(5);
	list.push_front(17);

	std::cout << *list.begin() << std::endl;
	std::cout << list.size() <<  std::endl;
	std::cout << std::endl;

	list.pop_front();

	std::cout << *list.begin() << std::endl;
	std::cout << list.size() <<  std::endl;
	std::cout << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(55);
	list.push_back(22);
	list.push_back(1265698);

	std::list<int>::iterator lit = list.begin();
	std::list<int>:: iterator lite = list.end();

	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::list<int> l(list);
	return 0;
}