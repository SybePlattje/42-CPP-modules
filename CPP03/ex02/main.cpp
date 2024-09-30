#include "FragTrap.hpp"

int main()
{
	FragTrap a;
	FragTrap b("FRG-TP");

	a.highFivesGuys();
	for (int index = 0; index < 100; index++)
	{
		a.attack("FRG-TP");
		b.takeDamage(30);
		b.beRepaired(30);
	}
	a.attack("something else");
	b.takeDamage(120);
	b.beRepaired(20);
}