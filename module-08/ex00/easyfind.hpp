#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &ctnr, int val)
{
	return std::find(ctnr.begin(), ctnr.end(), val);
}

#endif
