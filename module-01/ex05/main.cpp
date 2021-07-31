#include <iostream>
#include "Karen.hpp"

using std::cerr; using std::endl;

int main(int argc, char *argv[])
{

	if (argc != 2) {
		cerr << "Usage: karen <mode>" << endl;
		return 1;
	}

	Karen k;

	k.complain(argv[1]);

	return 0;
}
