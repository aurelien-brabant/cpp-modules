#include <iostream>
#include "Bureaucrat.hpp"

using std::cout;

int main(void)
{
	Bureaucrat b, b2("jacquouilles", 5);

	cout << b << b2;

	return 0;
}
