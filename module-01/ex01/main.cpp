#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>
#include "Zombie.hpp"

using std::bad_alloc;
using std::istringstream;
using std::cin; using std::cerr; using std::cout; using std::cout; using std::endl;
using std::string;

int main(int argc, char **argv)
{
	if (argc != 3) {
		cerr << "usage: brainz <number of zombies> <name>" << endl;
		return 1;
	}

	istringstream iss((string(argv[1])));
	int N;
	
	if (!(iss >> N)) {
		cerr << "Could not parse int" << endl;
	}
	
	if (N < 0) {
		cerr << "N must be a natural number (>= 0)" << endl;
		return 2;
	}

	try {
		Zombie *zbHorde = zombieHorde(N, argv[2]);

		for (int i = 0; i != N; ++i) {
			zbHorde[i].announce();
		}

		delete[] zbHorde;
	} catch(bad_alloc e) {
		cerr << "Dynamic allocated failed, bad_alloc exception caught" << endl;
	}

	return 0;
}
