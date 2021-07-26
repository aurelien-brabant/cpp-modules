#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <cstddef>
# include <iostream>
# include <iomanip>
# include <stdexcept>
# include <cstddef>
# include <sstream>

# include "Contact.h"

class PhoneBook {
	public:
		typedef size_t size_type;
		static const size_type contactLimitPerPhoneBook = 8;

		// empty phone book constructor
		PhoneBook(): contacts(), arraySize(0) {};

		PhoneBook &addContact(Contact const &contact);
		PhoneBook &removeContact(size_type index);
		Contact const *getContact(size_type index) const;
		PhoneBook &clear() { arraySize = 0; return *this; };
		PhoneBook &list();
		const PhoneBook &list() const;

		size_type size() const { return arraySize; };

	private:
		Contact contacts[contactLimitPerPhoneBook];
		size_t	arraySize;
		std::string formatField(std::string s) const;
};

PhoneBook &PhoneBook::addContact(Contact const &contact)
{
	if (size() == contactLimitPerPhoneBook) {
		removeContact(0);
	}
	contacts[arraySize++] = contact;
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
	return contacts + index;
}

PhoneBook &PhoneBook::removeContact(size_type index)
{
	if (index >= size()) {
		std::ostringstream oss;
		oss << "No contact at index " << index << ": index out of bounds";
		throw std::out_of_range(oss.str());
		return *this;
	}

	--arraySize;
	for (size_type i = index; i != size(); ++i) {
		contacts[i] = contacts[i + 1];	
	}

	return *this;
}

const PhoneBook &PhoneBook::list() const
{
	std::cout << std::setfill('-') << std::setw(54) << "\n" << std::setfill(' ');
	std::cout << "| " << std::setw(10) << "Index" << " | " << std::setw(10) << "First name" 
		<< " | " << std::setw(10) << "Last name" << " | " << std::setw(10) << "Nickname" << " |\n";

	for (size_type i = 0; i != size(); ++i) {
		Contact const &c = contacts[i];
		std::cout << "| " << std::setw(10) << i << " | " << std::setw(10) << formatField(c.getFirstName()) << " | "
			<< std::setw(10) << formatField(c.getLastName()) << " | " << std::setw(10) << formatField(c.getNickname()) << " |\n";
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

// private helpers

std::string PhoneBook::formatField(std::string s) const
{
	if (s.size() > 10) {
		s.resize(10);
		s[9] = '.';
	}
	return s;
}

#endif
