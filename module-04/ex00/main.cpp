#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

using std::cout; using std::endl;

int main(void)
{
    const Animal* meta = new Animal();
    cout << *meta << endl;

    const Animal *dog = new Dog();
    cout << *dog << endl;

    cout << Animal(*dog) << endl;

    const Dog normalDog, copiedDog(normalDog);

    cout << copiedDog << endl;

    delete dog;
    delete meta;

    return 0;
}