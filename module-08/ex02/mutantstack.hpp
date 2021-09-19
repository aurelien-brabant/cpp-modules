#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;	
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;	

		// provided for sake of completeness
		typedef T value_type;
		typedef std::stack<T> container_type;

		MutantStack(void): std::stack<T>()
		{
		}

		MutantStack(MutantStack const & rhs)
		{
			*this = rhs;
		}

		~MutantStack(void)
		{
		}

		MutantStack & operator=(MutantStack const & rhs)
		{
			std::stack<T>::operator=(rhs);
		}

		iterator begin(void)
		{
			return this->c.begin();
		}

		iterator end(void)
		{
			return this->c.end();
		}

		const_iterator start(void) const
		{
			return this->c.begin();
		}

		const_iterator end(void) const
		{
			return this->c.end();
		}
};

#endif
