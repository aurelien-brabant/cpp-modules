#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

using std::cout; using std::endl;

Cure::Cure(void): AMateria("ice")
{
}

// Actually, there is nothing to copy.

Cure& Cure::operator=(Cure const& rhs)
{
	(void)rhs;
	return *this;
}

Cure::Cure(Cure const& rhs): AMateria("cure")
{
	*this = rhs;
}

Cure* Cure::clone(void) const
{
	return new Cure(*this);
}

void Cure::use(ICharacter & target)
{
	cout << "* heals " << target.getName() << "'s wounds*" << endl;
}
