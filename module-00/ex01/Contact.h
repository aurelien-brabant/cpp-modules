#ifndef CONTACT_H
# define CONTACT_H
# include <string>
# include <cctype>
# include <iostream>

static std::string &stringCapitalize(std::string &s)
{
	for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
		*it = toupper(*it);		
	}
	return (s);
}

static std::string &markAsEmpty(std::string &s)
{
	if (s.find_first_not_of(' ') == std::string::npos) {
		s = "(empty)";
	}
	return s;
}

class Contact {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	public:
		Contact(): firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {};
		Contact(std::string _firstName, std::string _lastName, std::string _nickname,
				std::string _phoneNumber, std::string _darkestSecret):
				firstName(markAsEmpty(_firstName)), lastName(markAsEmpty(stringCapitalize(_lastName))),
				nickname(markAsEmpty(_nickname)), phoneNumber(markAsEmpty(_phoneNumber)), 
				darkestSecret(markAsEmpty(_darkestSecret)) {};

		std::string const &getFirstName() const { return firstName; };
		std::string const &getLastName() const { return lastName; };
		std::string const &getNickname() const { return nickname; };
		std::string const &getPhone() const { return phoneNumber; };
		std::string const &getDarkestSecret() const { return darkestSecret; };

		std::ostream &print(std::ostream &os = std::cout) const;
};

// Defined outside the class to improve readability

inline std::ostream& Contact::print(std::ostream &os) const
{ 
	return os << "first name: " << firstName
			<< "\nlast name: " << lastName
			<< "\nnickname: " << nickname
			<< "\nphone: " << phoneNumber
			<< "\ndarkest secret: " << darkestSecret
			<< std::flush;
}

std::ostream& operator<<(std::ostream &os, Contact const &contact)
{
	return contact.print(os);
}

#endif
