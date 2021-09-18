#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"

using std::vector;
using std::list;
using std::cout;

int main(void)
{
	vector<int> vi(10);

	for (vector<int>::size_type i = 0; i != vi.size(); ++i) {
		vi[i] = i;
	}

	vector<int>::iterator r = ::easyfind(vi, 3);

	cout << "Found " << *r << " at index " << (r - vi.begin()) << "\n";

	vector<int>::iterator r2 = ::easyfind(vi, 42);

	if (r2 == vi.end()) {
		cout << "42 not found!\n";
	} else {
		cout << "WTF, found 42!\n";
	}	
	
	return 0;
}
