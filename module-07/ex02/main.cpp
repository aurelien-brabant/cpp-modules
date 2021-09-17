#include <iostream>
#include <stdexcept>
#include <string>
#include "Array.hpp"

using std::cout; using std::cerr;
using std::exception;
using std::string;

int main(void)
{
	Array<int> ai(5);

	for (int * it = ai.begin(); it != ai.end(); ++it) {
		*it = 42;
	}

	for (size_t i = 0; i != ai.size(); ++i) {
		cout << ai[i] << "\n";
	}

	try {
		ai[ai.size()] = 42; // should throw
	} catch (exception & e) {
		cerr << e.what() << "\n";
	}

	Array<int> aiCopy(ai);

	for (int * it = ai.begin(); it != ai.end(); ++it) {
		cout << *it << "\n";
	}

	Array<string> as(2);

	as[0] = "Hello, ";
	as[1] = "World!";

	for (size_t i = 0; i != as.size(); ++i) {
		cout << as[i];
	}

	cout << "\n";

	return 0;
}
