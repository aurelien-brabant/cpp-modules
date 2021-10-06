#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "span.hpp"

using std::vector;
using std::cout; using std::cerr;

vector<int> genRandomIntVec(size_t n, int max = 42)
{
	srand(time(0));

	vector<int> vi(n);

	for (size_t i = 0; i != vi.size(); ++i) {
		vi[i] = rand() % (max + 1) * (rand() % 2 ? 1 : -1);
	}

	return vi;
}

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 3) {
		cerr << "Usage: ./span <n> [max]\n";
		return EXIT_FAILURE;
	}
	
	int n = atoi(argv[1]);
	/*
	if (n < 2) {
		cerr << "Please provide _at least_ 2 numbers\n";
		return EXIT_FAILURE;
	}
	*/

	int max = argc == 3 ? atoi(argv[2]) : 42;

	vector<int> randomVi = genRandomIntVec(n, max);
	Span sp(n);

	sp.append(randomVi.begin(), randomVi.end());

	sp.printSorted(cout) << "\n";

	cout << "shortest: " << sp.shortestSpan() << "\n";
	cout << "longest: " << sp.longestSpan() << "\n";

	return EXIT_SUCCESS;
}
