#include "Zombie.hpp"

int main()
{
	int number = 5;
	Zombie* horde = NULL;
	horde = horde->zombieHorde(number, "timmy");
	for (int index = 0; index < number; index++)
		horde[index].announce();
	delete[] horde;
}