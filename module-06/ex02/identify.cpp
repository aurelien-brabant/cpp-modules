#include <cstdlib>
#include <ctime>
#include <iostream>
#include "identify.hpp"

using std::cout;

Base::~Base(void)
{
}

Base * generate(void)
{
	static size_t i = 0;

	srand(time(0) + i++);

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
	union {
		A *a;
		B *b;
		C *c;
	} trueClass;

	trueClass.a = dynamic_cast<A *>(p);
	if (trueClass.a) cout << "A";

	trueClass.b = dynamic_cast<B *>(p);
	if (trueClass.b) cout << "B";

	trueClass.c = dynamic_cast<C *>(p);
	if (trueClass.c) cout << "C";
}
