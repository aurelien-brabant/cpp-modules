#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

using std::exception;

using std::cout; using std::endl; using std::cerr;

int main(void)
{
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
	
	return 0;
}
