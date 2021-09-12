#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

using std::cout; using std::endl;

Cure::Cure(void): AMateria("cure")
{
}

Cure::~Cure(void)
{
}

Cure* Cure::clone(void) const
{
	return new Cure;
}

void Cure::use(ICharacter & target)
{
	cout << "* heals " << target.getName() << "'s wounds*" << endl;
}
