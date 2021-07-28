#pragma once
#ifndef CONTACT_H
# define CONTACT_H
# include <string>
# include <cctype>
# include <iostream>

class Contact {
	std::string _firstName, _lastName, _nickname, _phone, _darkestSecret;

	static std::string& _stringCapitalize(std::string &s);
	static std::string& _markAsEmpty(std::string &s);

	public:
		// default constructor is needed for array automatic initialization
		Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname,
				std::string phone, std::string darkestSecret);

		std::string const &getFirstName() const;
		std::string const &getLastName() const;
		std::string const &getNickname() const;
		std::string const &getPhone() const;
		std::string const &getDarkestSecret() const;

		std::ostream &print(std::ostream &os = std::cout) const;
};

std::ostream& operator<<(std::ostream &os, Contact const &contact);

#endif
