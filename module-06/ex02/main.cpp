#include <iostream>
#include <cstdlib>
#include "identify.hpp"

using std::cout;

int main(int argc, char **argv)
{
	if (argc != 2) {
		cout << "./identify <n>\n";
		return 1;
	}

	cout << "\033[0;33m* \033[0midentify(Base *)\n\033[0;34m* \033[0midentify(Base &)\n\n";

	for (int i = 0; i != atoi(argv[1]); ++i) {
		Base *b = generate();

		identify(b);
		identify(*b);
		cout << "\n";

		delete b;
	}

	return 0;
}
