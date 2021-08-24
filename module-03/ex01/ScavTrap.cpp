#include <iostream>
#include "ScavTrap.hpp"

using std::string;
using std::cout; using std::endl;

ScavTrap::ScavTrap(string const& name): ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;

	cout << "[\033[1;32mCTOR\033[0m] \033[1;33mScav\033[0mTrap \"" << _name << "\" created" << endl;
}

ScavTrap::~ScavTrap(void)
{
	cout << "[\033[1;31mDTOR\033[0m] \033[1;33mScav\033[0mTrap \"" << _name << "\" destroyed" << endl;
}

void	ScavTrap::attack(const std::string &target) const
{
	cout << "💥 Wooooooww! ScavTrap \"" << _name << "\" punched \"" << target << "\" and dealt " << _attack_damage << " damage points to it!" << endl;
}

void	ScavTrap::guardGate(void) const
{
	cout << "🛡️ \"" << _name << "\" has activated _GATE KEEPER_ mode!" << endl;
}
