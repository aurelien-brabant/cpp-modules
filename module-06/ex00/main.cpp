#include <iostream>
#include "ScalarConverter.hpp"
#include <string>

using std::cerr;
using std::cout;

double stod(std::string const & s);

int main(int argc, char **argv)
{
	if (argc != 2) {
		cerr << "Usage: ./scalcv <literal>\n";
		return 1;
	}

	(void)argv;

	//ScalarConverter scalcv;

	//cout << scalcv.detectType(argv[1]) << "\n";

	cout << stod("-54345.45") << "\n";
}
