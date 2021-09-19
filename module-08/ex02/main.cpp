#include <iostream>
#include <list>
#include "mutantstack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	std::cout << "\nIterating:\n\n";

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\nTesting same input with a std::list\n\n";

	std::list<int> list;

	list.push_back(5);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it) {
		std::cout << *it << "\n";	
	}

	return 0;
}
