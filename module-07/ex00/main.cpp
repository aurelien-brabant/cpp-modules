#include <iostream>
#include "whatever.hpp"

using std::cout;
using std::endl;

class Test
{
	int _x;
		
	public:
		// Because another constructor is declared, default constructor is not synthetized. However, the assignment operator does.
		Test(int x): _x(x) {}

		bool operator<(Test const & rhs) { return getX() < rhs.getX(); }
		bool operator>(Test const & rhs) { return getX() > rhs.getX(); }
		bool operator>=(Test const & rhs) { return getX() >= rhs.getX(); }
		bool operator<=(Test const & rhs) { return getX() <= rhs.getX(); }
		bool operator==(Test const & rhs) { return getX() == rhs.getX(); }

		int getX(void) const { return _x; }
};

int main(void) {

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// ADDITIONAL TESTS
	
	Test t(5), t2(15);

	cout << "\n----- Testing with class implementing all the comparison operators - no default CTOR -----\n\n";

	cout << t.getX() << " | " << t2.getX() << "\n"; // 5 | 15 expected

	::swap(t, t2);

	cout << t.getX() << " | " << t2.getX() << "\n"; // 15 | 5 expected

	// reswap
	::swap(t, t2);

	cout << "max: " << ::max(t, t2).getX() << "\n"; // 15 expected (t2.getX())

	cout << "min: " << ::min(t, t2).getX() << "\n"; // 5 expected (t.getX())

	Test t3(5);

	cout << "min with values that are equal: min(t, t3) == t3 is " << ((&::min(t, t3) == &t3) ? "true" : "false") << "\n";
	cout << "max with values that are equal: max(t, t3) == t3 is " << ((&::max(t, t3) == &t3) ? "true" : "false") << "\n";

	return 0;
}
