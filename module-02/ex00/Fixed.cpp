#include <iostream>
#include "Fixed.hpp"

using std::cout; using std::endl;

Fixed::Fixed(void): _fixed(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(Fixed &f)
{
	cout << "Copy constructor called" << endl;
	*this = f;
}

Fixed::~Fixed(void)
{
	cout << "Destructor called" << endl;
}

void Fixed::setRawBits(int const raw)
{

   	_fixed = raw;
}

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;

	return _fixed;
}

Fixed	&Fixed::operator=(Fixed &rhs)
{
	cout << "Assignation operator called" << endl;

	// guard self assignment
	if (this == &rhs) return *this;

	_fixed = rhs.getRawBits();

	// lhs is returned
	return *this;
}
