#include "Contact.h"

Contact::Contact(void) {};

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
					std::string phone, std::string darkestSecret):
					_firstName(_markAsEmpty(firstName)), _lastName(_markAsEmpty(_stringCapitalize(lastName))),
					_nickname(_markAsEmpty(nickname)), _phone(_markAsEmpty(phone)), 
					_darkestSecret(_markAsEmpty(darkestSecret)) {};

// getters

std::string const& Contact::getFirstName(void) const { return _firstName; };

std::string const& Contact::getLastName(void) const { return _lastName; };

std::string const& Contact::getNickname(void) const { return _nickname; };

std::string const& Contact::getPhone(void) const { return _phone; };

std::string const& Contact::getDarkestSecret(void) const { return _darkestSecret; };

// Defined outside the class to improve readability

inline std::ostream &Contact::print(std::ostream &os) const
{
    return os << "first name: " << _firstName
              << "\nlast name: " << _lastName
              << "\nnickname: " << _nickname
              << "\nphone: " << _phone
              << "\ndarkest secret: " << _darkestSecret
              << std::flush;
}

std::string &Contact::_stringCapitalize(std::string &s)
{
    for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
        *it = toupper(*it);
    }
    return (s);
}

std::string &Contact::_markAsEmpty(std::string &s)
{
	if (s.find_first_not_of(" \n\v\t\f\r") == std::string::npos) {
		s = "(empty)";
	}
	return s;
}

std::ostream &operator<<(std::ostream &os, Contact const &contact)
{
    return contact.print(os);
}
