#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

using std::cout; using std::endl;

int main(void)
{
	#ifdef DEBUG /* ex02 TEST CODE */
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
		}

		{
			FragTrap ft;
			ft.highFiveGuys();
		}

		{
			cout << "\033[0;35mTesting copy constructor and assignment operator\033[0m" << endl;

			FragTrap f1("FG-1"), f2 = FragTrap(f1);

			f2.setName("FG-2");
			
			/* should use ClapTrap's version of attack since FragTrap is not required to define its version */
			f1.attack(f2.getName());

			f1 = f2;
		}
	#endif /* END OF ex02 TEST CODE */

	DiamondTrap dt, dt2("DIAMOND-0x01");

	dt.attack(dt2.getName());
	dt.highFiveGuys();
	dt.guardGate();
	dt.whoAmI();

	/* test copy control */

	DiamondTrap tmp(dt2);
	dt2 = dt;
	dt2.whoAmI();

	dt2 = tmp;
	dt2.whoAmI();

	return 0;
}
