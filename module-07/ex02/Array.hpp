#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <cstddef>
# include <stdexcept>

template <typename T>
class Array
{
	unsigned int _size;
	T * _data;

	public:
		Array(unsigned int size = 0): _size(size), _data(new T[_size])
		{
		}

		Array(Array const &rhs): _size(rhs._size), _data(new T[_size])
		{
			*this = rhs;
		}

		~Array(void)
		{
			delete[] _data;
		}
		
		Array & operator=(Array const & rhs)
		{
			if (this != &rhs) {
				for (unsigned int i = 0; i != size(); ++i) {
					_data[i] = rhs._data[i];
				}
			}

			return *this;
		}

		T& operator[](unsigned int i) throw(std::out_of_range)
		{
			if (i >= size()) {
				throw std::out_of_range("Index out of the range of the array");
			}

			return _data[i];
		}

		unsigned int size(void)
		{
			return _size;
		}

		T * begin(void)
		{
			return _data;
		}

		T * end(void)
		{
			return _data + size();
		}
};

#endif
