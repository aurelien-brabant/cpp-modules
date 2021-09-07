#include "Cure.hpp"

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
