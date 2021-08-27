#include <iostream>
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

using std::string;
using std::cout; using std::endl;

DiamondTrap::DiamondTrap(string const& name): ClapTrap(name + "_clap_name")
{
	_hit_points = 100 /* FragTrap */;
	_energy_points = 50; /* ScavTrap */
	_attack_damage = 30 /* FragTrap */;
}

DiamondTrap::DiamondTrap(DiamondTrap const &dt)
{
	*this = dt;
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
