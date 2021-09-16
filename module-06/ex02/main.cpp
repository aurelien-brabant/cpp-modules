#include <iostream>
#include "identify.hpp"

using std::cout;

int main(void)
{
	for (size_t i = 0; i != 10; ++i) {
		Base *b = generate();

		identify(b);
		cout << "\n";

		delete b;
	}
	
	return 0;
}
