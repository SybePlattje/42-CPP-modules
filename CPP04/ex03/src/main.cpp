#include "../includes/Character.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/ICharacter.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	src->createMateria("fire");
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->equip(tmp);
	me->use(0, *me);
	me->use(1, *bob);
	
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(0);

	std::cout << tmp->getType() << std::endl;

	AMateria* clone = tmp->clone();
	
	delete clone;
	delete bob;
	delete me;
	delete src;
}
