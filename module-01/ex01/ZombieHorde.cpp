#include <memory>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zbHorde = new Zombie[N];

	// constructs horde of zombies, all sharing the same name parameter
	
	for (int i = 0; i != N; ++i) {
		// Using a setter here avoids the copy of a temporary object:
		// doing such a thing would have been problematic because the temporary object
		// would have been destructed at the end of the function, thus output would have been misleading.
		zbHorde[i].setName(name);
	}

	return zbHorde;
}
