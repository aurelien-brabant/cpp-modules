#include <stdexcept>
#include <iostream>
#include "Zombie.hpp"

using std::bad_alloc;
using std::cerr; using std::endl;

int main(void)
{
	try {
		Zombie *zbLoc = newZombie("heap zombie");
		zbLoc->announce();
		// release memory allocated for the Zombie pointed by zbLoc
		delete zbLoc;
	} catch(bad_alloc alloc) {
		cerr << "Dynamic allocation failed, caught bad_alloc exception" << endl;	
	}
	
	randomChump("stack zombie");
	
	return 0;
}
