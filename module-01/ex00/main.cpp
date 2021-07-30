#include "Zombie.hpp"

int main(void)
{
	Zombie *zbLoc = newZombie("heap zombie");
	
	zbLoc->announce();

	// Because zbLoc points to a dynamically allocated Zombie object, we need to release this memory at some point.
	// we do so by using the delete keyword that is responsible for freeing memory which is allocated dynamically.
	delete zbLoc;

	randomChump("stack zombie");
	
	return 0;
}
