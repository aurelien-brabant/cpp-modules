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

class Contact {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	public:
		Contact(): firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {};
		Contact(std::string _firstName, std::string _lastName, std::string _nickname,
				std::string _phoneNumber, std::string _darkestSecret):
				firstName(_firstName), lastName(stringCapitalize(_lastName)), nickname(_nickname),
				phoneNumber(_phoneNumber), darkestSecret(_darkestSecret) {};

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
	return os << lastName << " " << firstName << " a.k.a \"" << nickname << "\"\n"
		<< "Phone: " << phoneNumber << "\n" << "\033[0;31mDarkest secret\033[0m: "
		<< darkestSecret;
}

std::ostream& operator<<(std::ostream &os, Contact const &contact)
{
	return contact.print(os);
}

#endif
