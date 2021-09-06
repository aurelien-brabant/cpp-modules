#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

using std::cout; using std::endl;

int main(void)
{
    // TEST ANIMAL
    const Animal* animal = new Animal();
    cout << *animal << endl;
    delete animal;

    // TEST DOG
    const Animal *dog = new Dog();
    cout << *dog << endl;
    delete dog;

    // TEST CAT
    Animal *cat = new Cat();
    cout << *cat << endl;
    delete cat;

    // TEST WRONG CAT
    WrongAnimal *wa = new WrongCat();
    // should output WrongAnimal's sound, not WrongCat's. Because WrongAnimal's did not declare makeSound as virtual
    cout << *wa << endl;
    delete wa;

    return 0;
}
