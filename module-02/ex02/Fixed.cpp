#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/* REFERENCES:
**
** https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c
** https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html
** https://en.wikipedia.org/wiki/Fixed-point_arithmetic
** https://spin.atomicobject.com/2012/03/15/simple-fixed-point-math
*/

using std::cout; using std::endl;

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
	_fixed = roundf(fixedVal * (1 << Fixed::getNbOfFractionalBits()));
}

int Fixed::toInt(void) const
{
	return _fixed >> 8;
}

float Fixed::toFloat(void) const
{
	return ((float) _fixed / (1 << Fixed::getNbOfFractionalBits()));
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

Fixed &Fixed::operator=(Fixed const &rhs)
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

std::ostream &operator<<(std::ostream &lhs, Fixed const &rhs)
{
	lhs << rhs.toFloat();

	return lhs;
}


bool operator==(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() == rhs.getRawBits();
}

bool operator!=(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() != rhs.getRawBits();
}

bool operator>=(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() >= rhs.getRawBits();
}

bool operator<=(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() <= rhs.getRawBits();
}

bool operator>(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() > rhs.getRawBits();
}

bool operator<(Fixed const &lhs, Fixed const &rhs)
{
	return lhs.getRawBits() < rhs.getRawBits();
}

Fixed operator+(Fixed const &lhs, Fixed const &rhs)
{
	Fixed f;
	
	f.setRawBits(lhs.getRawBits() + rhs.getRawBits());
	
	return f;
}

Fixed operator-(Fixed const &lhs, Fixed const &rhs)
{
	Fixed f;
	
	f.setRawBits(lhs.getRawBits() - rhs.getRawBits());
	
	return f;
}

Fixed operator*(Fixed const &lhs, Fixed const &rhs)
{
	Fixed f;

	f.setRawBits((static_cast<int64_t>(lhs.getRawBits()) * static_cast<int64_t>(rhs.getRawBits()))
		/ (1 << Fixed::getNbOfFractionalBits()));

	return f;
}

Fixed operator/(Fixed const &lhs, Fixed const &rhs)
{
	Fixed f;
	
	f.setRawBits((static_cast<int64_t>(lhs.getRawBits()) * (1 << Fixed::getNbOfFractionalBits()))
		 / rhs.getRawBits());

	return f;
}

Fixed &Fixed::operator++()
{
	*this = *this + Fixed(1.0f / (1 << Fixed::getNbOfFractionalBits()));
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	*this = *this - Fixed(1.0f / (1 << Fixed::getNbOfFractionalBits()));

	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	operator--();

	return tmp;
}

// static member functions

unsigned Fixed::getNbOfFractionalBits(void)
{
	return _fbNb;
}

Fixed const &Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1 < f2) return f1;
	return f2;
}

Fixed &Fixed::min(Fixed  &f1, Fixed  &f2)
{
	return const_cast<Fixed &>(Fixed::min(const_cast<Fixed const &>(f1), const_cast<Fixed const &>(f2)));
}

Fixed const &Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1 > f2) return f1;
	return f2;
}

Fixed  &Fixed::max(Fixed  &f1, Fixed  &f2)
{
	return const_cast<Fixed &>(Fixed::max(const_cast<Fixed const &>(f1), const_cast<Fixed const &>(f2)));
}
