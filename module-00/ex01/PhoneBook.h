#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <cstddef>
# include "Contact.h"

class PhoneBook {
	public:
		typedef size_t size_type;

		// empty phone book constructor
		PhoneBook();

		PhoneBook &addContact(Contact const &contact);
		PhoneBook &removeContact(size_type index);
		Contact const *getContact(size_type index) const;
		PhoneBook &clear(void);
		PhoneBook &list(void);
		const PhoneBook &list(void) const;

		size_type size(void) const;

	private:
		static const size_type _contactLimitPerPhoneBook = 8;
		Contact _contacts[_contactLimitPerPhoneBook];
		size_t	_arraySize;
		static std::string _formatField(std::string s);
};

#endif
