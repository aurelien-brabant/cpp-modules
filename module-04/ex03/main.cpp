#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	Ice ice;
	Cure cure;
	Character rere("Réré"), roro("Roro");

	rere.equip(&ice);

	rere.use(0, roro);

	rere.equip(&cure);
	rere.use(1, roro);

	return 0;
}
