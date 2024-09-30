#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include "../include/Base.hpp"
#include <random>
#include <iostream>

Base* generate(void)
{
	Base* base;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 3);

	switch (dis(gen))
	{
		case 1:
			base = new B();
			std::cout << "it is created as B" << std::endl;
			break;
		case 2:
			base = new C();
			std::cout << "it is created as C" << std::endl;
			break;
		default:
			base = new A();
			std::cout << "it is created as A" << std::endl;
			break;
	}
	return base;
}

void identify(Base* p)
{
	Base* a = dynamic_cast<A*>(p);
	Base* b = dynamic_cast<B*>(p);
	Base* c = dynamic_cast<C*>(p);
	if (a != NULL)
		std::cout << "it is found as A" << std::endl;
	else if (b != NULL)
		std::cout << "it is found as B" << std::endl;
	else if (c != NULL)
		std::cout << "it is found as C" << std::endl;
	else
		std::cerr << "it is found as unkown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		Base& a = dynamic_cast<A&>(p);
		std::cout << "it is found as A" << std::endl;
		(void)a;
	} catch(const std::exception& e) {}
	try
	{
		Base& b = dynamic_cast<B&>(p);
		std::cout << "it is found as B" << std::endl;
		(void)b;
	} catch(const std::exception& e) {}
	try
	{
		Base& c = dynamic_cast<C&>(p);
		std::cout << "it is found as C" << std::endl;
		(void)c;
	} catch(const std::exception& e) {}
}

int main(void)
{
	Base* base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
}
