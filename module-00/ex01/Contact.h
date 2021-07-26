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
		Contact() {};
		Contact(std::string firstName, std::string lastName, std::string nickname,
				std::string phone, std::string darkestSecret):
				_firstName(_markAsEmpty(firstName)), _lastName(_markAsEmpty(_stringCapitalize(lastName))),
				_nickname(_markAsEmpty(nickname)), _phone(_markAsEmpty(phone)), 
				_darkestSecret(_markAsEmpty(darkestSecret)) {};

		std::string const &getFirstName() const { return _firstName; };
		std::string const &getLastName() const { return _lastName; };
		std::string const &getNickname() const { return _nickname; };
		std::string const &getPhone() const { return _phone; };
		std::string const &getDarkestSecret() const { return _darkestSecret; };

		std::ostream &print(std::ostream &os = std::cout) const;
};

std::ostream& operator<<(std::ostream &os, Contact const &contact);

#endif
