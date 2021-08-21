#include <iostream>
#include "Fixed.hpp"

using std::cout;

int main(void) {

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	cout << a << "\n";
	cout << ++a << "\n";
	cout << a << "\n";
	cout << a++ << "\n";
	cout << a << "\n";
	cout << b << "\n";
	cout << Fixed::max(a, b) << "\n\n";

	Fixed c;
	Fixed const d(Fixed(10.5f) / Fixed(2));

	cout << c << "\n";
	cout << --c << "\n";
	cout << c << "\n";
	cout << c-- << "\n";
	cout << c << "\n";

	cout << d << "\n";

	cout << Fixed::min(c, d) << "\n";

	Fixed e;
	cout << Fixed::min(c, e) << std::endl;

	return 0;
}
