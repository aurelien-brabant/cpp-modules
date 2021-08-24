#include <iostream>
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

using std::string;
using std::cout; using std::endl;

DiamondTrap::DiamondTrap(string const& name): ClapTrap(name + "_clap_name"), _name(name)
{
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
}

void	DiamondTrap::whoAmI(void) const
{
	cout << _name << " (" << ClapTrap::_name << ")" << endl;
}
