#include <iostream>
#include "WrongCat.hpp"

using std::cout; using std::endl;

WrongCat::WrongCat(): WrongAnimal()
{
    cout << "[CTOR] WrongCat (default)" << endl; 
    _type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& rhs)
{
    cout << "[CTOR] WrongCat (copy)" << endl; 
    *this = rhs;
}

WrongCat::~WrongCat()
{
    cout << "[DTOR] WrongCat" << endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    WrongAnimal::operator=(rhs);
    _type = "WrongCat";

    return *this;
}

void WrongCat::makeSound(void) const
{
    cout << "Meoooowwwwwww!";
}