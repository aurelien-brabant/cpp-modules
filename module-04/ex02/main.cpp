#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

using std::cout; using std::endl;

int main(void)
{
	// uncomment the line below to get a compilation error
	
	//Animal a;

	// Cat and Dog are still be able to be instanciated as they provide an implementation for makeSound
	Cat c;
	Dog d;
	
	Animal *animal = &c;
	animal->makeSound();
	cout << "\n";

	animal = &d;
	animal->makeSound();
	cout << "\n";
	
	return 0;
}
