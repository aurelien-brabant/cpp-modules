#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

using std::string;
using std::cout; using std::endl;

AMateria::AMateria(string const& type): _type(type)
{
}

string const& AMateria::getType(void) const
{
	return _type;
}

// Because use is not pure virtual, it requires an implementation.

void AMateria::use(ICharacter & target)
{
	cout << "Using unknown materia type (supposed type: " << _type << ") on "
		<< target.getName() << "!" << endl;
}
