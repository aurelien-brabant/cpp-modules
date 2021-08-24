#include <iostream>
#include "FragTrap.hpp"

using std::string;
using std::cout; using std::endl;

FragTrap::FragTrap(string const& name): ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;

	cout << "[\033[1;32mCTOR\033[0m] \033[1;35mFrag\033[0mTrap \"" << _name << "\" created" << endl;
}

FragTrap::~FragTrap(void)
{
	cout << "[\033[1;31mDTOR\033[0m] \033[1;35mFrag\033[0mTrap \"" << _name << "\" destroyed" << endl;
}

void	FragTrap::highFiveGuys(void) const
{
	cout << "🙌 \"" << _name << "\" shouts: GIVE ME FIVE GUYS!!" << endl;
}
