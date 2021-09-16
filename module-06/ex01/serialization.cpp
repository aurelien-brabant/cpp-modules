#include "serialization.hpp"

using std::string;

Data::Data(string const & bookName, size_t pageNb): bookName(bookName), pageNb(pageNb)
{
}

Data::Data(Data const & rhs)
{
	*this = rhs;
}

Data & Data::operator=(Data const & rhs)
{
	if (this != &rhs) {
		bookName = rhs.bookName;
		pageNb = rhs.pageNb;	
	}

	return *this;
}


std::ostream & operator<<(std::ostream & os, Data const & rhs)
{
	os << rhs.bookName << " (" << rhs.pageNb << " pages)";

	return os;
}

uintptr_t	serialize(Data *data)
{
	return reinterpret_cast<uintptr_t>(data);
}

Data *		deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
