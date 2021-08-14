#include <iostream>
#include <cmath>
#include <climits>
#include "Fixed.hpp"

/* REFERENCES:
** https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c
** https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html
*/

using std::cout; using std::endl;

float Fixed::scaleFactor = 1.0f / (1 << _fbNb);

/* - CONSTRUCTORS - */

Fixed::Fixed(void): _fixed(0)
{
	#ifdef DEBUG
		cout << "Default constructor called" << endl;
	#endif
}

Fixed::Fixed(Fixed const &f)
{
	#ifdef DEBUG
		cout << "Copy constructor called" << endl;
	#endif
	*this = f;
}

Fixed::Fixed(int const fixedVal)
{
	#ifdef DEBUG
		cout << "Int constructor called" << endl;
	#endif
	_fixed = fixedVal << _fbNb;
}

Fixed::Fixed(float const fixedVal)
{
	#ifdef DEBUG
		cout << "Float constructor called" << endl;
	#endif
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
	#ifdef DEBUG
		cout << "Destructor called" << endl;
	#endif
}

void Fixed::setRawBits(int const raw)
{
   	_fixed = raw;
}

int Fixed::getRawBits(void) const
{
	#ifdef DEBUG
		cout << "getRawBits member function called" << endl;
	#endif

	return _fixed;
}

/* - OPERATORS - */

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	#ifdef DEBUG
		cout << "Assignation operator called" << endl;
	#endif

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

/* - Comparison operators - */

bool	operator==(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() == rhs.getRawBits();
}

bool	operator!=(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() != rhs.getRawBits();
}

bool	operator>=(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() >= rhs.getRawBits();
}

bool	operator<=(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() <= rhs.getRawBits();
}

bool	operator>(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() > rhs.getRawBits();
}

bool	operator<(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() < rhs.getRawBits();
}

/* - ARITHMETIC OPERATORS - */

Fixed			operator+(Fixed const &lhs, Fixed const &rhs)
{
	Fixed f;
	
	f.setRawBits(lhs.getRawBits() + rhs.getRawBits());
	
	return f;
}

Fixed			operator-(Fixed const &lhs, Fixed const &rhs)
{
	Fixed f;
	
	f.setRawBits(lhs.getRawBits() - rhs.getRawBits());
	
	return f;
}

Fixed			operator*(Fixed const &lhs, Fixed const &rhs)
{
	Fixed f;
	
	f.setRawBits(lhs.getRawBits() * rhs.getRawBits());
	
	return f;
}

Fixed			operator/(Fixed const &lhs, Fixed const &rhs)
{
	Fixed f;
	
	f.setRawBits(lhs.getRawBits() / rhs.getRawBits());
	
	return f;
}

/* - POST/PRE INCREMENTATION/DECREMENTATION - */

// pre-increment
Fixed	&Fixed::operator++()
{
	*this = *this + Fixed(Fixed::scaleFactor);
	return *this;
}

// post-increment
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	operator++();
	return tmp;
}

// pre-increment
Fixed	&Fixed::operator--()
{
	*this = *this - Fixed(Fixed::scaleFactor);
	return *this;
}

// post-increment

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	operator--();
	return tmp;
}
