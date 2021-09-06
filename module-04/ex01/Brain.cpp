#include <string>
#include <iostream>
#include "Brain.hpp"

using std::string;
using std::cout; using std::endl; using std::ostream;

Brain::Brain()
{
}

Brain::~Brain()
{
}

Brain::Brain(Brain const& rhs)
{
	*this = rhs;
}

/* Perform a deep copy, not a shallow one: all the ideas are copied from rhs to lhs */

Brain& Brain::operator=(Brain const& rhs)
{
	if (this != &rhs){
		for (size_t i = 0; i != idea_nb; ++i) {
			ideas[i] = rhs.ideas[i];
		}
	}

	return *this;
}

ostream& operator<<(ostream& os, Brain const& rhs)
{
	return os;
}