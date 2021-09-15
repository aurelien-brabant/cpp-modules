#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

using std::exception;

using std::cout; using std::endl; using std::cerr;

int main(void)
{
	// BUREAUCRAT CODE

	Bureaucrat anonymous, jjq("Jean-Jacques", 1), jjqBis(jjq);

	cout << anonymous << "\n" << jjq << "\n" << jjqBis << "\n";

	try {
		anonymous.promote(); // 150 -> 149
		anonymous.demote(); // 149 -> 150
		anonymous.demote(); // 150 -> 151: SHOULD THROW!

		cout << "This should never be printed, otherwise there is a problem!" << endl;
	} catch(exception & e) {
		cerr << "\033[1;31m" << e.what() << "\033[0m" << endl;
	}

	try {
		jjq.demote(); // 1 -> 2
		jjq.promote(); // 2 -> 1
		jjq.promote(); // 1 -> 0: SHOULD THROW!

		cout << "This should never be printed, otherwise there is a problem!" << endl;
	} catch (exception & e) {
		cerr << "\033[1;31m" << e.what() << "\033[0m" << endl;
	}

	Bureaucrat weakBureaucrat("Weaky", 150);

	// ShrubberyCreationForm

	ShrubberyCreationForm scf("home"), scfBis(scf);

	cout << scf << "\n" << scfBis << "\n";

	jjq.signForm(scf);

	jjq.executeForm(scf);

	// RobotomyRequestForm

	RobotomyRequestForm rrf("someone"), rrfBis(rrf);	

	cout << rrf << "\n" << rrfBis << "\n";

	jjq.signForm(rrf);	
	
	jjq.executeForm(rrf);

	// PresidentialPardonForm

	PresidentialPardonForm ppf("someone"), ppfBis(ppf);

	cout << ppf << "\n" << ppfBis << "\n";

	jjq.signForm(ppf);

	jjq.executeForm(ppf);

	weakBureaucrat.executeForm(ppf); // Should give an error: grade of weakBureaucrat too low.

	// Intern code

	Intern intern;

	Form *robotomyForJjq = intern.makeForm("robotomy request", "Jean-Jacques");

	jjq.signForm(*robotomyForJjq);

	jjq.executeForm(*robotomyForJjq);

	delete robotomyForJjq;

	Form *unknownForm = intern.makeForm("hey ho hey ho", "someome");

	cout << unknownForm << "\n";

	return 0;
}
