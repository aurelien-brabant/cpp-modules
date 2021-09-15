#include <iostream>
#include "ScalarConverter.hpp"

using std::cerr;
using std::cout;

int main(int argc, char **argv)
{
	if (argc != 2) {
		cerr << "Usage: ./scalcv <literal>\n";
		return 1;
	}

	ScalarConverter scalcv;

	cout << scalcv.detectType(argv[1]) << "\n";
}
