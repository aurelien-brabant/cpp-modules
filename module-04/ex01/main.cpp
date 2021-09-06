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
        if (i < array_size / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    Dog *dog = dynamic_cast<Dog *>(animals[0]);
    Cat *cat = dynamic_cast<Cat *>(animals[array_size - 1]);

    (void)dog;

    cat->brain->setIdea(0, "cat's idea");
    cout << cat->brain->getIdea(0) << endl;

    //test copy
    Cat stackCat = *cat;
    stackCat.brain->setIdea(0, "Modified cat's idea");

    cout << cat->brain->getIdea(0) << endl;
    cout << stackCat.brain->getIdea(0) << endl;

    for (size_t i = 0; i != array_size; ++i) {
        delete animals[i];
    }
    delete[] animals;

    return 0;
}