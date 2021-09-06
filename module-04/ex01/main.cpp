#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

using std::cout; using std::endl;

int main(void)
{
    size_t const array_size = 10;

    Animal **animals = new Animal*[array_size];

    // Initialize array of pointers to Animal, half Dog half Cat.
    for (size_t i = 0; i != array_size; ++i) {
        if (i < 50) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    Cat *cat = dynamic_cast<Cat *>(animals[50]);
    cat->meditate();

    for (size_t i = 0; i != array_size; ++i) {
        delete animals[i];
    }
    delete[] animals;

    return 0;
}