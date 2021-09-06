#include <string>
#include "AMateria.hpp"

using std::string;

AMateria::AMateria(string const& type): _type(type)
{
}

string const& AMateria::getType(void) const
{
	return _type;
}
