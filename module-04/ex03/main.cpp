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

	Ice *iceToLearn = new Ice();

	stackSrc.learnMateria(iceToLearn); // iceToLearn will be added, even if Ice recipe is already known by the source.
	stackSrc.learnMateria(iceToLearn); // nothing will be added because the exact same recipe is already in the recipe list.
	stackSrc.learnMateria(new Cure()); // ok: has 4 recipes
	stackSrc.learnMateria(new Cure()); // should not crash: maximum amount of recipe reached.

	stackMe.use(0, *bob);
	stackMe.use(1, *bob);

	stackMe.equip(stackSrc.createMateria("ice"));
	stackMe.equip(stackSrc.createMateria("ice"));
	stackMe.equip(stackSrc.createMateria("ice"));

	// attempted to add 3 more materias to character's inventory. Only the first two must be effectively
	// stored, and the program must NOT crash.

	delete bob;
	delete src;
	delete me;
	return 0;
}
