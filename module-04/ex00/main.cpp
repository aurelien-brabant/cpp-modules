#include <iostream>
#include "Animal.hpp"

using std::cout; using std::endl;

int main(void)
{
    const Animal* meta = new Animal();

    cout << *meta << endl;

    return 0;
}