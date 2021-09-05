#include <iostream>
#include "WrongAnimal.hpp"

using std::string;
using std::cout; using std::endl;

WrongAnimal::WrongAnimal(): _type("Animal")
{
    cout << "[CTOR] WrongAnimal (default)" << endl; 
}

WrongAnimal::WrongAnimal(WrongAnimal const& rhs)
{
    cout << "[CTOR] WrongAnimal (copy)" << endl; 
    *this = rhs;
}

WrongAnimal::~WrongAnimal(void)
{
    cout << "[DTOR] WrongAnimal" << endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs)
{
    (void)rhs;
    _type = "WrongAnimal";

    return *this;
}

string WrongAnimal::getType(void) const
{
    return _type;
}

void WrongAnimal::makeSound(void) const
{
    cout << "* Unbearable animal sound *";
}

/*
 * Not required by the subject, but implemented for easy and brief testing.
 */

std::ostream &operator<<(std::ostream &os, WrongAnimal const& a)
{
    os << a.getType() << ": ";
    a.makeSound();

    return os;
}