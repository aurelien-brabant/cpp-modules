#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

using std::cout;
using std::string;

RobotomyRequestForm::RobotomyRequestForm(string const & target): Form(target + "_robotomy", 45, 72), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rhs)
{
	*this = rhs;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	Form::operator=(rhs);
	return *this;
}

void RobotomyRequestForm::executeAction(void) const
{
	static int i = 0;

	srand(time(0) - ++i); // use a different seed each time for pseudo-random
	
	if (rand() % 2) {
		cout << "RIZZZZZ... " << _target << " robotomized successfully\n";
	} else {
		cout << "Robotomization failed: you're probably not lucky enough!\n";
	}
}
