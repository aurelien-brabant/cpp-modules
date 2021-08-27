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

DiamondTrap::DiamondTrap(DiamondTrap const &dt)
{
	*this = dt;
	cout << "[\033[1;32mCTOR\033[0m] (COPY) \033[1;34mClap\033[0mTrap \"" << _name << "\" created" << endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this != &rhs) {
		/*
		* Reuse of the ClapTrap assignement operator, which already manages to copy the ClapTrap's specs.
		* The only difference here is that we need to ensure the private name declared by DiamondTrap is correctly
		* assigned.
		*/
		this->ClapTrap::operator=(rhs); /* this keyword is optional, but maybe makes more sense for a beginner */
		_name = rhs._name;
	}

	return *this;
}


void	DiamondTrap::whoAmI(void) const
{
	cout << _name << " (" << ClapTrap::_name << ")" << endl;
}
