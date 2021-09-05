#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

using std::cout; using std::endl;

int main(void)
{
    const Animal* animal = new Animal();
    cout << *animal << endl;
    delete animal;

    const Animal *dog = new Dog();
    cout << *dog << endl;

    // testing animal copy, should output animal's caracteristics, not Dog's
    cout << Animal(*dog) << endl;

    delete dog;

    Animal *cat = new Cat();
    cout << *cat << endl;

    return 0;
}