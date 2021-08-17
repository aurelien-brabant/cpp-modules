#include <iostream>
#include "Fixed.hpp"

using std::cout;

int main(void) {

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	cout << "--- Main \033[1;35mfrom the SUBJECT \033[0m---\n\n";

	cout << a << "\n";
	cout << ++a << "\n";
	cout << a << "\n";
	cout << a++ << "\n";
	cout << a << "\n";
	cout << b << "\n";
	cout << Fixed::max(a, b) << "\n\n";


	Fixed c;
	Fixed const d(Fixed(10.5f) / Fixed(2));

	cout << "Testing: pre/post DEcrement operator\n\n";

	cout << c << "\n";
	cout << --c << "\n";
	cout << c << "\n";
	cout << c-- << "\n";
	cout << c << "\n";

	cout << "Testing: division operator\n\n";

	cout << d << "\n";

	cout << "Testing: Fixed::min\n\n";

	cout << Fixed::min(c, d) << "\n\n";

	return 0;
}
