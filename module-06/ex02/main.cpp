#include <iostream>
#include "identify.hpp"

using std::cout;

int main(void)
{
	cout << "\033[0;33m* \033[0midentify(Base *)\n\033[0;34m* \033[0midentify(Base &)\n\n";

	for (size_t i = 0; i != 10; ++i) {
		Base *b = generate();

		identify(b);
		identify(*b);
		cout << "\n";

		delete b;
	}

	return 0;
}
