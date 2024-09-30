#include "ScavTrap.hpp"

int main()
{
	ScavTrap a;
	ScavTrap b("SCP4P-TP");

	b.guardGate();
	b.guardGate();
	for (int index = 0; index < 51; index++)
	{
		a.attack("SCP4P-TP");
		b.takeDamage(20);
		b.beRepaired(20);
	}
	b.takeDamage(100);
	b.beRepaired(20);
}