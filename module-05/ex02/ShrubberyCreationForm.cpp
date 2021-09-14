#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.hpp"

using std::string;
using std::ofstream;
using std::cerr; using std::cout;

ShrubberyCreationForm::ShrubberyCreationForm(string const & target):
	Form(target + "_shrubbery", 137, 147)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & rhs)
{
	*this = rhs;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	Form::operator=(rhs);

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::executeAction(void) const
{
	ofstream ofs(getName().c_str());

	if (!ofs) {
		cerr << "Could not open a new file in current directory\n";	
	}

	for (size_t i = 0; i != 5; ++i) {
		ofs <<
		"    *    \n" <<
		"   ---   \n" <<
		"  -----  \n" <<
		" ------- \n" <<
		"---------\n" <<
		"   |||   \n\n";
	}
}
