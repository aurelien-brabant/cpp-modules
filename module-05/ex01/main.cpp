#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	// FORM CODE
	
	Form f, f2("Social Security Form", 2, 1), f2bis(f2);

	cout << f << "\n" << f2 << "\n" << f2bis << endl;

	jjq.signForm(f2); // okay: f2's signGrade is 1, and jjq's grade is 1 too

	jjq.demote(); // 1 -> 2
	jjq.signForm(f2); // f2's signGrade is 1, so this is an error

	// invalid grade in form constructor

	try {
		Form f("invalid form", 1, 151);
	} catch (std::exception & e) {
		cerr << "\033[1;31m" << e.what() << "\033[0m" << endl;
	}

	try {
		Form f("invalid form", 0, 50);
	} catch (std::exception & e) {
		cerr << "\033[1;31m" << e.what() << "\033[0m" << endl;
	}

	return 0;
}
