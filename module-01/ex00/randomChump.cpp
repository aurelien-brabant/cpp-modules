#include "Zombie.hpp"

// A zombie is constructed using the passed name, then it is announced.
// Storage for that zombie is allocated on the stack, and is destroyed
// when randomChump returns.

void randomChump(std::string name)
{
	Zombie zb(name);

	zb.announce();
}
