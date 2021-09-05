#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

using std::cout; using std::endl;

Dog::Dog(): Animal()
{
    _type = "Dog";
    cout << "[CTOR] Dog (default)" << endl; 
}

Dog::Dog(Dog const& rhs)
{
    cout << "[CTOR] Dog (copy)" << endl; 
    *this = rhs;
}

Dog const& Dog::operator=(Dog const& rhs)
{
    Animal::operator=(rhs);
    _type = "Dog";

    return *this;
}

Dog::~Dog()
{
    cout << "[DTOR] Dog" << endl;
}

void Dog::makeSound(void) const
{
    cout << "Woof! Woof!";
}