#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	Ice *ice = new Ice;
	Cure *cure = new Cure;
	Character rere("Réré"), roro("Roro");

	rere.equip(ice);

	rere.use(0, roro);

	rere.equip(cure);

	// a deep copy is performed
	roro = rere;

	rere.printDebug();
	roro.printDebug();

	return 0;
}
