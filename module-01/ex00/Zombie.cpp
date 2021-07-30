#include <iostream>
#include "Zombie.hpp"

using std::cout; using std::endl;
using std::string;

Zombie::Zombie(string const &name): _name(name) {};

void Zombie::announce(void) const
{
	std::cout << "<" << _name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "<" << _name << ">" << " Arghhhh (\033[0;31mdead\033[0m)" << std::endl;
}
