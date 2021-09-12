#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

using std::cout; using std::endl;

Ice::Ice(void): AMateria("ice")
{
}

Ice::~Ice(void)
{
}

Ice* Ice::clone(void) const
{
	return new Ice();
}

void Ice::use(ICharacter & target)
{
	cout << "*Shoots an ice bolt at " << target.getName() << "*" << endl;	
}
