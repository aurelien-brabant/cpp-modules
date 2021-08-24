#include <iostream>
#include "ClapTrap.hpp"

using std::string;
using std::cout; using std::endl;

ClapTrap::ClapTrap(string const &name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	cout << "[\033[1;32mCTOR\033[0m] ClapTrap \"" << _name << "\" created" << endl;
}

ClapTrap::ClapTrap(ClapTrap const& cp)
{
	*this = cp;
};

ClapTrap& ClapTrap::operator=(const ClapTrap &cp)
{
	if (this != &cp) {
		_name = cp._name;
		_hit_points = cp._hit_points;
		_energy_points = cp._energy_points;
		_attack_damage = cp._attack_damage;
	}

	return *this;
}

void				ClapTrap::setName(const std::string &name) { _name = name; }

std::string const&	ClapTrap::getName(void) { return _name; }

ClapTrap::~ClapTrap(void)
{
	cout << "[\033[1;31mDTOR\033[0m] ClapTrap \"" << _name << "\" destroyed" << endl;
}

void	ClapTrap::attack(std::string const& target)
{
	cout << "ClapTrap \"" << _name << "\" attacks \"" << target << "\", causing " << _attack_damage << " points of damage!" << endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	cout << "Oof! ClapTrap \"" << _name << "\" just took " << amount << " points of damage!" << endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	cout << "Yay! ClapTrap \"" << _name << "\" healed for " << amount << " energy points." << endl;
}
