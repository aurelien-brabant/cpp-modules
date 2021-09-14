#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"

using std::string;
using std::cout;

PresidentialPardonForm::PresidentialPardonForm(string const & target):
	Form(target + "_presidential_pardon", 5, 25), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs)
{
	*this = rhs;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	Form::operator=(rhs);

	if (this != &rhs) {
		_target = rhs._target;
	}

	return *this;
}

void PresidentialPardonForm::executeAction(void) const
{
	cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
