#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

using std::cout; using std::endl;

Dog::Dog(): Animal(), brain(new Brain())
{
    _type = "Dog";
    #ifdef DEBUG
    cout << "[CTOR] Dog (default)" << endl; 
    #endif
}

Dog::Dog(Dog const& rhs)
{
    *this = rhs;
    #ifdef DEBUG
    cout << "[CTOR] Dog (copy)" << endl;
    #endif
}

Dog const& Dog::operator=(Dog const& rhs)
{
    Animal::operator=(rhs);
    _type = "Dog";

	if (this != &rhs) {
		delete brain;
		brain = new Brain(*rhs.brain);
	}
    
    return *this;
}

Dog::~Dog()
{
    delete brain;
    #ifdef DEBUG
    cout << "[DTOR] Dog" << endl;
    #endif
}

void Dog::makeSound(void) const
{
    cout << "Woof! Woof!";
}
