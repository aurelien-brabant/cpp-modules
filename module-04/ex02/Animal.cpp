#include <iostream>
#include "Animal.hpp"

using std::string;
using std::cout; using std::endl;

Animal::Animal(): _type("Animal")
{
    #ifdef DEBUG
    cout << "[CTOR] Animal (default)" << endl; 
    #endif
}

Animal::Animal(Animal const& rhs)
{
    *this = rhs;
    #ifdef DEBUG
    cout << "[CTOR] Animal (copy)" << endl; 
    #endif 
}

Animal::~Animal(void)
{
    #ifdef DEBUG
    cout << "[DTOR] Animal" << endl;
    #endif
}

Animal& Animal::operator=(Animal const& rhs)
{
    (void)rhs;
    _type = "Animal";

    return *this;
}

string Animal::getType(void) const
{
    return _type;
}

void Animal::makeSound(void) const
{
    cout << "* Unbearable animal sound *";
}

/*
 * Not required by the subject, but implemented for easy and brief testing.
 */

std::ostream &operator<<(std::ostream &os, Animal const& a)
{
    os << a.getType() << ": ";
    a.makeSound();

    return os;
}