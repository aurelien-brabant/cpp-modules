#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::string;
using std::cerr;

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Form * Intern::allocateRobotomyRequestForm(string const & target) const
{
	return new RobotomyRequestForm(target);
}

Form * Intern::allocateShrubberyCreationForm(string const & target) const
{
	return new ShrubberyCreationForm(target);
}

Form * Intern::allocatePresidentialPardonForm(string const & target) const
{
	return new PresidentialPardonForm(target);
}

const Intern::FormTypeEntry Intern::formEntries[] = {
	{ "robotomy request", &Intern::allocateRobotomyRequestForm },
	{ "presidential pardon", &Intern::allocatePresidentialPardonForm },
	{ "shrubbery creation", &Intern::allocateShrubberyCreationForm }
};

Form * Intern::makeForm(string const & formType, string const & target) const
{
	size_t allocatorsNb = sizeof (formEntries) / sizeof (FormTypeEntry);

	for (size_t i = 0; i != allocatorsNb; ++i) {
		if (formEntries[i].formType == formType) {
			return (this->*(formEntries[i].formAllocator))(target);
		}
	}

	cerr << formType << " is not a valid form\n";
	return 0;
}
