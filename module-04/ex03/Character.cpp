#include <iostream>
#include "Character.hpp"

using std::cerr;

Character::Character(std::string const & name): _name(name), _materia()
{
}

void Character::equip(AMateria *m)
{
	for (size_t i = 0; i != _inventory_size; ++i) {
		// if slot is empty, materia is equiped there.
		if (!_materia[i]) {
			_materia[i] = m;
			return ;
		}
	}

	cerr << "Could not equip materia: inventory is full\n";
}

void Character::unequip(int idx)
{
	if (!_materia[idx]) {
		cerr << "Nothing in slot #" << idx << " of player's inventory\n";
	}
}

void Character::use(int idx, ICharacter & target)
{
	if (!_materia[idx]) {
		cerr << "Nothing in slot #" << idx << " of player's inventory\n";
	}
	// TODO: use materia when AMateria::use is properly implemented
	(void) target;
}

std::string const & Character::getName(void) const
{
	return _name;
}
