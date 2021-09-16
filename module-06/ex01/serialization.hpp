#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP
# include <string>
# include <iostream>

struct Data
{
	std::string bookName;
	size_t pageNb;

	Data(std::string const & bookName = "default", size_t pageNb = std::string::npos);
	Data(Data const & rhs);

	Data & operator=(Data const & rhs);
};

std::ostream & operator<<(std::ostream & os, Data const & rhs);

uintptr_t	serialize(Data *data);
Data *		deserialize(uintptr_t raw);

#endif
