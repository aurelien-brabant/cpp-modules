#include "Contact.h"

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