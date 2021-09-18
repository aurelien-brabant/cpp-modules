#ifndef SPAN_HPP
# define SPAN_HPP
# include <stdexcept>
# include <vector>
# include <iostream>

class Span
{
	unsigned int _n;
	std::vector<int> _data;

	public:
		class FullException: public std::exception
		{
			char const * what(void) const throw();
		};

		Span(unsigned int n = 0);
		Span(Span const & rhs);
		~Span(void);

		Span & operator=(Span const & rhs);

		void addNumber(int i) throw (FullException);
		void append(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) throw (FullException);

		size_t shortestSpan(void) const;
		size_t longestSpan(void) const;

		std::vector<int> const & getInternalData(void) const;
		std::ostream & printSorted(std::ostream & os);
};

#endif
