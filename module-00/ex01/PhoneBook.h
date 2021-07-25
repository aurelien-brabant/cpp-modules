#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <cstddef>
# include <iostream>
# include <iomanip>
# include <stdexcept>
# include <cstddef>

# include "Contact.h"

static const size_t contactLimitPerPhoneBook = 8;

class PhoneBook {
	
	Contact contacts[contactLimitPerPhoneBook];
	size_t	arraySize;

	public:
		typedef size_t size_type;
		PhoneBook(): contacts(), arraySize(0) {};
		PhoneBook &add(Contact const &contact);
		PhoneBook &remove(size_type index);
		Contact const *get(size_type index);
		PhoneBook &list();
		size_type size() { return arraySize; };
};

PhoneBook &PhoneBook::add(Contact const &contact)
{
	if (size() == contactLimitPerPhoneBook) {
		remove(0);
	}
	contacts[arraySize++] = contact;
	return *this;
}

Contact const *PhoneBook::get(size_type index)
{
	if (index >= size()) {
		throw std::out_of_range("No contact at given index");
		return 0;
	}
	return contacts + index;
}

PhoneBook &PhoneBook::remove(size_type index)
{
	if (index >= size()) {
		throw std::out_of_range("No contact at given index");
		return *this;
	}

	--arraySize;
	for (size_type i = index; i != size(); ++i) {
		contacts[i] = contacts[i + 1];	
	}

	return *this;
}

PhoneBook &PhoneBook::list() 
{
	std::cout << std::setfill('-') << std::setw(54) << "\n" << std::setfill(' ');
	std::cout << "| " << std::setw(10) << "Index" << " | " << std::setw(10) << "First name" 
		<< " | " << std::setw(10) << "Last name" << " | " << std::setw(10) << "Nickname" << " |\n";

	for (size_type i = 0; i != size(); ++i) {
		Contact const &c = contacts[i];
		std::cout << "| " << std::setw(10) << i << " | " << std::setw(10) << c.getFirstName() << " | "
			<< std::setw(10) << c.getLastName() << " | " << std::setw(10) << c.getNickname() << " |\n";
	}

	std::cout << std::setfill('-') << std::setw(54) << "\n" << std::setfill(' ');

	std::cout << std::flush;
	return *this;
}

#endif
