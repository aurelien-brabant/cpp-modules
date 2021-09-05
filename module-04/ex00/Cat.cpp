#include <iostream>
#include "Cat.hpp"

using std::cout; using std::endl;

Cat::Cat(): Animal()
{
    cout << "[CTOR] Cat (default)" << endl; 
    _type = "Cat";
}

Cat::Cat(Cat const& rhs)
{
    cout << "[CTOR] Cat (copy)" << endl; 
    *this = rhs;
}

Cat::~Cat()
{
    cout << "[DTOR] Cat" << endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    Animal::operator=(rhs);
    _type = "Cat";

    return *this;
}

void Cat::makeSound(void) const
{
    cout << "Meoooowwwwwww!";
}