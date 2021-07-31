#include <string>
#include <iostream>
#include <iomanip>

using std::string;
using std::cout; using std::flush; using std::endl;
using std::setw; using std::left; using std::setfill; using std::right;

int main(void)
{
	string s("HI THIS IS BRAIN"), *stringPTR = &s, &stringREF = s;

	cout << "Printing addresses:\n" << right
		<< setfill('-') << setw(30) << "" << setfill(' ') << left
		<< setw(15) << "\n&s" << "= " << &s 
		<< setw(15) << "\nstringPTR" << "= " << stringPTR
		<< setw(15) << "\n&stringREF" << "= " << &stringREF << "\n\n";

	cout << "Printing string:\n" << right
		<< setfill('-') << setw(30) << "" << setfill(' ') << left
		<< setw(15) << "\n*stringPTR" << "= " << *stringPTR
		<< setw(15) << "\nstringREF" << "= " << stringREF << "\n";

	return 0;
}
