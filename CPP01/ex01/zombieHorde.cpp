#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie* zombie = new Zombie[N];
	for (int index = 0; index < N; index++)
		 new (&zombie[index]) Zombie(name);
	return zombie;
}
