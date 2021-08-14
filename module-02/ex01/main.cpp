#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a(75.345f);

	std::cout << a.toInt() << std::endl;

	return 0;
}
