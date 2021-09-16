#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include "identify.hpp"

using std::cout;

Base::~Base(void)
{
}

Base * generate(void)
{
	static size_t i = 0;

	srand(time(0) - i++);

	switch (rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return 0; // should never happen, to silence warning
	}
}

void identify(Base * p)
{
	cout << "\033[0;33m";
	
	if (dynamic_cast<A *>(p)) cout << "A";

	else if (dynamic_cast<B *>(p)) cout << "B";

	else if (dynamic_cast<C *>(p)) cout << "C";

	cout << "\033[0m";
}

void identify(Base & p)
{
	// if no exception is caught, it means dynamic_cast was successful. In this case, print the correct class name
	// and return.
	cout << "\033[0;34m";

	try {
		(void) dynamic_cast<A &>(p);
		cout << "A";
	} catch (std::bad_cast) {};

	try {
		(void) dynamic_cast<B &>(p);
		cout << "B";
	} catch (std::bad_cast) {};

	try {
		(void) dynamic_cast<C &>(p);
		cout << "C";
	} catch (std::bad_cast) {};

	cout << "\033[0m";
}
