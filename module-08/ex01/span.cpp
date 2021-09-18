#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include "span.hpp"

using std::vector;
using std::cout;

Span::Span(unsigned int n): _n(n), _data(0)
{
}

Span::Span(Span const & rhs)
{
	*this = rhs;
}

Span::~Span(void)
{
}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs) {
		_data = rhs._data;	
		_n = rhs._n;
	}

	return *this;
}

void Span::addNumber(int i) throw(FullException)
{
	if (_data.size() == _n) {
		throw FullException();
	}

	_data.push_back(i);
}

void Span::append(vector<int>::const_iterator begin, vector<int>::const_iterator end) throw (FullException)
{
	while (begin != end) {
		addNumber(*begin++);
	}
}

size_t Span::longestSpan(void) const
{
	vector<int> sorted(_data);
	std::sort(sorted.begin(), sorted.end());

	return abs(sorted.back() - sorted.front());
}

size_t Span::shortestSpan(void) const
{
	vector<int> sorted(_data);
	std::sort(sorted.begin(), sorted.end());

	return abs(sorted[1] - sorted[0]);	
}

vector<int> const & Span::getInternalData(void) const
{
	return _data;
}

std::ostream & Span::printSorted(std::ostream & os)
{
	vector<int> sorted(_data);

	std::sort(sorted.begin(), sorted.end());

	for (size_t i = 0; i != sorted.size(); ++i) {
		os << sorted[i];
		if (i != sorted.size() - 1) {
			os << " ";
		}
	}
	
	return os;
}

char const * Span::FullException::what(void) const throw()
{
	return "Span is full!";
}
