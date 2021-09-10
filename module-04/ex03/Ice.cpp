#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

using std::cout; using std::endl;

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

void Ice::use(ICharacter & target)
{
	cout << "*Shoots an ice bolt at " << target.getName() << "*" << endl;	
}
