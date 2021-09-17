#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T & el1, T & el2)
{
	T tmp = el2;

	el2 = el1;
	el1 = tmp;
}

template<typename T>
T & min(T & el1, T & el2)
{
	return el1 < el2 ? el1 : el2;
}

template<typename T>
T & max(T & el1, T & el2)
{
	return el1 > el2 ? el1 : el2;
}

#endif
