#include <iostream>
#include <cmath>
#include "iter.hpp"

using std::cout;

class Foo
{
	int _x;

	public:
		Foo(int x): _x(x) {};

		int getX(void) { return _x; }
};

void printFooX(Foo & f)
{
	cout << f.getX() << "\n";
}

void printInt(int & i)
{
	cout << i << "\n";
}

void pow2(int &exp)
{
	exp = pow(2, exp);
}

int main(void)
{
	cout << "Test with array of ints\n\n";

	int ia[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	size_t iaSize = sizeof (ia) / sizeof (int);

	::iter(ia, iaSize, &pow2);
	::iter(ia, iaSize, &printInt);

	cout << "\nTest with array of classes\n\n";

	Foo fa[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // implicit Foo(int) calls

	::iter(fa, sizeof (fa) / sizeof (Foo), &printFooX);

	return 0;
}
