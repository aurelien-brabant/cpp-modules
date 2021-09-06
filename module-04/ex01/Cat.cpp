#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

using std::cout; using std::endl;

Cat::Cat(): Animal(), brain(new Brain())
{
    #ifdef DEBUG
    cout << "[CTOR] Cat (default)" << endl; 
    #endif
    _type = "Cat";
}

Cat::Cat(Cat const& rhs)
{
    #ifdef DEBUG
    cout << "[CTOR] Cat (copy)" << endl;
    #endif
    *this = rhs;
}

Cat::~Cat()
{
    delete brain;
    #ifdef DEBUG
    cout << "[DTOR] Cat" << endl;
    #endif
}

Cat& Cat::operator=(const Cat& rhs)
{
    Animal::operator=(rhs);
    _type = "Cat";

    if (this != &rhs) {
        // deep copy: this and rhs will not share the same array.
        brain = rhs.brain;
    }

    return *this;
}

void Cat::makeSound(void) const
{
    cout << "Meoooowwwwwww!";
}

void Cat::meditate(void)
{
    for (size_t i = 0; i != Brain::idea_nb; ++i) {
        brain->ideas[i] = "";
    }
}