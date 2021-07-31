#include <string>
#include <iostream>
#include "HumanB.hpp"

using std::string;
using std::cout; using std::endl;

HumanB::HumanB(std::string const& name): _name(name), _weapon(0) {}

void HumanB::setWeapon(Weapon const &weapon) { _weapon = &weapon; }

void HumanB::attack(void)
{
	if (!_weapon) {
		cout << _name << " attacks with his fists! (no weapon)" << endl;
	} else {
		cout << _name << " attacks with his " << _weapon->getType() << endl;
	}
}
