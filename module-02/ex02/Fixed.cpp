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

const std::ostream &printDebug(std::string const &msg);

Fixed::Fixed(void): _fixed(0)
{
	printDebug("Default constructor called");
}

Fixed::Fixed(Fixed const &f)
{
	printDebug("Copy constructor called");

	*this = f;
}

Fixed::Fixed(int const fixedVal)
{
	printDebug("Int constructor called");
	_fixed = fixedVal << _fbNb;
}

Fixed::Fixed(float const fixedVal)
{
	printDebug("Float constructor called");
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
	printDebug("Destructor called"); 
}

void Fixed::setRawBits(int const raw)
{
   	_fixed = raw;
}

int Fixed::getRawBits(void) const
{
	printDebug("getRawBits member function called");

	return _fixed;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	
	printDebug("Assignation operator called");

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
	printDebug("const min static member called");

	if (f1 < f2) return f1;
	return f2;
}

Fixed &Fixed::min(Fixed  &f1, Fixed  &f2)
{
	printDebug("non-const min static member called");

	return const_cast<Fixed &>(Fixed::min(static_cast<Fixed const &>(f1), f2));
}

Fixed const &Fixed::max(Fixed const &f1, Fixed const &f2)
{
	printDebug("const max static member called");

	if (f1 > f2) return f1;
	return f2;
}

Fixed  &Fixed::max(Fixed &f1, Fixed  &f2)
{
	printDebug("non-const max static member called");

	return const_cast<Fixed &>(Fixed::max(static_cast<Fixed const &>(f1), f2));
}
