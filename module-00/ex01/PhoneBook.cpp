#include "PhoneBook.h"
#include <sstream>
# include <iostream>
# include <iomanip>
# include <stdexcept>
# include <sstream>

PhoneBook &PhoneBook::addContact(Contact const &contact)
{
	if (size() == _contactLimitPerPhoneBook) {
		removeContact(0);
	}
	_contacts[_arraySize++] = contact;
	return *this;
}

Contact const *PhoneBook::getContact(size_type index) const
{
	if (index >= size()) {
		std::ostringstream oss;
		oss << "No contact at index " << index << ": index out of bounds";
		throw std::out_of_range(oss.str());
		return 0;
	}
	return _contacts + index;
}

PhoneBook &PhoneBook::removeContact(size_type index)
{
	if (index >= size()) {
		std::ostringstream oss;
		oss << "No contact at index " << index << ": index out of bounds";
		throw std::out_of_range(oss.str());
		return *this;
	}

	--_arraySize;
	for (size_type i = index; i != size(); ++i) {
		_contacts[i] = _contacts[i + 1];	
	}

	return *this;
}

const PhoneBook &PhoneBook::list() const
{
	std::cout << std::setfill('-') << std::setw(54) << "\n" << std::setfill(' ');
	std::cout << "| " << std::setw(10) << "Index" << " | " << std::setw(10) << "First name" 
		<< " | " << std::setw(10) << "Last name" << " | " << std::setw(10) << "Nickname" << " |\n";

	for (size_type i = 0; i != size(); ++i) {
		Contact const &c = _contacts[i];
		std::cout << "| " << std::setw(10) << i << " | " << std::setw(10) << _formatField(c.getFirstName()) << " | "
			<< std::setw(10) << _formatField(c.getLastName()) << " | " << std::setw(10) << _formatField(c.getNickname()) << " |\n";
	}

	std::cout << std::setfill('-') << std::setw(54) << "\n" << std::setfill(' ');

	std::cout << std::flush;
	return *this;
}

// non const variant calls const variant, but returns a non const reference to PhoneBook

PhoneBook &PhoneBook::list()
{
	static_cast<const PhoneBook *>(this)->list();
	return *this;
}

// static private helpers

std::string PhoneBook::_formatField(std::string s) 
{
	if (s.size() > 10) {
		s.resize(10);
		s[9] = '.';
	}
	return s;
}