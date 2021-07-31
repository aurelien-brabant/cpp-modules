#include <string>
#include <iostream>
#include "HumanA.hpp"

using std::string;
using std::cout; using std::endl;

HumanA::HumanA(std::string const& name, Weapon const& weapon): _name(name), _weapon(weapon){};

void HumanA::attack(void)
{
	cout << _name << " attacks with his " << _weapon.getType() << endl;
}
