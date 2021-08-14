#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/* REFERENCES:
** https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c
** https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html
*/

using std::cout; using std::endl;

/* - CONSTRUCTORS - */

Fixed::Fixed(void): _fixed(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(Fixed const &f)
{
	cout << "Copy constructor called" << endl;
	*this = f;
}

Fixed::Fixed(int const fixedVal)
{
	cout << "Int constructor called" << endl;
	_fixed = fixedVal << _fbNb;
}

Fixed::Fixed(float const fixedVal)
{
	cout << "Float constructor called" << endl;
	_fixed = roundf(fixedVal * (1 << _fbNb));
}

/* - FIXED POINT CONVERSION - */

int	Fixed::toInt(void) const
{
	return _fixed >> 8;
}

float Fixed::toFloat(void) const
{
	return ((float) _fixed / (float)(1 << _fbNb));
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

/* - OPERATORS - */

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	cout << "Assignation operator called" << endl;

	// guard self assignment
	if (this == &rhs) return *this;

	_fixed = rhs.getRawBits();

	// lhs is returned
	return *this;
}

std::ostream	&operator<<(std::ostream &lhs, Fixed const &rhs)
{
	lhs << rhs.toFloat();

	return lhs;
}
