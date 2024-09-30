#include "../includes/DiamondTrap.hpp"

int main()
{
	DiamondTrap a;
	DiamondTrap b("DMT-TP");

	a.whoAmI();
	for (int index = 0; index < 51; index++)
	{
		a.attack("DMT-TP");
		b.takeDamage(20);
		b.beRepaired(20);
	}
	a.attack("something else");
	b.takeDamage(120);
	b.beRepaired(20);
	
	DiamondTrap c;
	
}