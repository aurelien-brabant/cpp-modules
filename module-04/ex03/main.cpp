#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main(void)
{
	// SUBJECT
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	// MORE TESTING - Test copy for MateriaSource and Character
	MateriaSource stackSrc(*dynamic_cast<MateriaSource *>(src));
	Character stackMe(*dynamic_cast<Character *>(me));

	AMateria *ice = stackSrc.createMateria("ice");
	AMateria *cure = stackSrc.createMateria("cure");

	stackMe.equip(ice);
	stackMe.equip(cure);
	stackMe.use(0, *bob);
	stackMe.use(1, *bob);

	delete bob;
	delete src;
	delete me;
	return 0;
}
