#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
}

// Actually, there is nothing to copy.

Ice& Ice::operator=(Ice const& rhs)
{
	(void)rhs;
	return *this;
}

Ice::Ice(Ice const& rhs): AMateria("ice")
{
	*this = rhs;
}

Ice* Ice::clone(void) const
{
	return new Ice(*this);
}
