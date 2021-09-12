#include <iostream>
#include "Character.hpp"

using std::cout; using std::endl;

Character::Character(std::string const & name): _name(name), _materia()
{
}

Character::Character(Character const & rhs): _materia()
{
	*this = rhs;
}

Character::~Character(void)
{
	for (int i = 0; i != _inventory_size; ++i) {
		delete _materia[i];
	}
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs) {
		_name = rhs._name;
	
		for (int i = 0; i != _inventory_size; ++i) {
			delete _materia[i];
			if (rhs._materia[i]) {
				_materia[i] = rhs._materia[i]->clone();
			}	
		}
	}
	return *this;
}

bool Character::isValidMateria(int idx)
{
	return (idx >= 0 && idx < _inventory_size) && _materia[idx];
}

void Character::equip(AMateria *m)
{
	// do not equip materia if it is already present
	for (size_t i = 0; i != _inventory_size; ++i) {
		if (_materia[i] == m) {
			return ;
		}
	}	

	for (size_t i = 0; i != _inventory_size; ++i) {
		// if slot is empty, materia is equiped there.
		if (!_materia[i]) {
			_materia[i] = m;
			return ;
		}
	}
	// could not equip materia: all slots were taken: inventory is full.
}

void Character::unequip(int idx)
{
	if (isValidMateria(idx)) {
		_materia[idx] = 0;
	}
}

void Character::use(int idx, ICharacter & target)
{
	if (isValidMateria(idx)) {
		_materia[idx]->use(target);
	}
}

std::string const & Character::getName(void) const
{
	return _name;
}

void Character::printDebug(void)
{
	cout << "name = " << getName() << "\nInventory: = [\n";

	for (int i = 0; i != _inventory_size; ++i) {
		if (!_materia[i]) {
			cout << "Empty";
		} else {
			cout << _materia[i]->getType() << " (" << _materia[i] << ")";
		}
		if (i != _inventory_size - 1) {
			cout << ",\n";
		}
	}

	cout << "\n]" << endl;
}
