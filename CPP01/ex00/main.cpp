#include "Zombie.hpp"

int main()
{
	std::string name = "Rose";
	Zombie* a = Zombie::newZombie(name);
	a->announce();
	name = "Rando";
	Zombie::randomChump(name);
	name = "Lando";
	Zombie* b = Zombie::newZombie(name);
	b->announce();
	delete a;
	delete b;
}