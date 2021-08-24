#include "ClapTrap.hpp"

int main(void)
{
	// test default CTOR
	ClapTrap anonymousClapTrap;

	// test name CTOR
	ClapTrap namedClapTrap("named claptrap");

	// test attack
	anonymousClapTrap.attack(namedClapTrap.getName());
	namedClapTrap.takeDamage(10);

	// test overload of assignment operator
	anonymousClapTrap = namedClapTrap;
	anonymousClapTrap.setName("Copy of namedClapTrap, previously anonymousClapTrap");
	anonymousClapTrap.beRepaired(10);

	return 0;
}
