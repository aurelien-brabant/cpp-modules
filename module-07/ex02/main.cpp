#include "Array.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using std::cout; using std::cerr;
using std::exception;
using std::string;

int main(void)
{
	cout << "\n=== Testing empty array ===\n";

	Array<bool> ab;
	cout << "ab's size: " << ab.size() << "\n";

	cout << "\n=== Testing normal array ===\n";

	Array<int> ai(5);

	for (int * it = ai.begin(); it != ai.end(); ++it) {
		*it = 42;
	}

	for (size_t i = 0; i != ai.size(); ++i) {
		cout << ai[i] << "\n";
	}
	
	cout << "\n=== Testing subscript operator exception ===\n";

	try {
		ai[ai.size()] = 42; // should throw
	} catch (exception & e) {
		cerr << e.what() << "\n";
	}

	cout << "\n=== TESTING COPY ===\n";
	cout << "ai (previous array) copied into aiCopy\n";
	cout << "Every ai element is multiplied by 2\n";

	Array<int> aiCopy(ai);

	cout << "ai's content after mult:\n";

	for (int* it = ai.begin(); it != ai.end(); ++it) {
		*it *= 2;
		cout << *it << "\n";
	}

	cout << "aiCopy's content:\n";

	for (int* it = aiCopy.begin(); it != aiCopy.end(); ++it) {
		cout << *it << "\n";
	}

	cout << "\n=== Array of strings ===\n";

	Array<string> as(2);

	as[0] = "Hello, ";
	as[1] = "World!";

	for (size_t i = 0; i != as.size(); ++i) {
		cout << as[i];
	}

	cout << "\n";

	return 0;
}
