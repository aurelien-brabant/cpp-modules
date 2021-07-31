#include <iostream>
#include <string>
#include "Karen.hpp"

using std::cout; using std::endl; using std::cerr;
using std::string;

inline static void printLevel(Karen const &k, string const &levelName)
{
	cout << "[ " << levelName << " ]" << "\n";
	k.complain(levelName);	
	cout << "\n";
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		cerr << "Usage: karen <mode>" << endl;
		return 1;
	}

	Karen k;	
	Karen::intMode im = Karen::getIntMode(argv[1]); // implicit conversion to std::string

	switch (im)
	{
		case Karen::MODE_DEBUG:
			printLevel(k, "DEBUG");

		case Karen::MODE_INFO:
			printLevel(k, "INFO");

		case Karen::MODE_WARNING:
			printLevel(k, "WARNING");

		case Karen::MODE_ERROR:
			printLevel(k, "ERROR");
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
			break;
	}

	return 0;
}
