#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("CLP4P-TP");

	for (int index = 0; index < 11; index++)
	{
		a.attack("CLP4P-TP");
		b.takeDamage(0);
	}
	b.beRepaired(1);
	b.takeDamage(10);
	b.beRepaired(2);
}