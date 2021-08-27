#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

using std::cout; using std::endl;

int main(void)
{
	#ifdef DEBUG
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
	}
	#endif
	
	{
		ScavTrap defaultScavTrap;
		ScavTrap namedScavTrap("Named ScavTrap");

		namedScavTrap.attack(defaultScavTrap.getName());
		namedScavTrap.guardGate();
	}

	cout << "\033[0;35mTesting copy constructor and assignment operator\033[0m" << endl;

	{
		ScavTrap dumbScavTrap("Dumb ScavTrap");
		ScavTrap copiedScavTrap = ScavTrap(dumbScavTrap);
		copiedScavTrap.attack("Random scavtrap");
	}

	return 0;
}
