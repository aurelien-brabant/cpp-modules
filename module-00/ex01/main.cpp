#include <iostream>
#include <cctype>
#include <stdexcept>

#include "Contact.h"
#include "PhoneBook.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::istream;
using std::out_of_range;

static istream	&promptLine(std::string const &promptContent, std::string &line)
{
	if (cin) {
		cout << promptContent;
		getline(cin, line);
	}
	return cin;
}

int main(void)
{
	PhoneBook pb;
	string cmd;

	while (promptLine("\033[0;34mPhoneBook\033[0m> ", cmd)) {

		 if (cmd == "ADD") {
			std::string firstName, lastName, nickname, phone, darkestSecret;

			promptLine("firstName> ", firstName);
			promptLine("lastName> ", lastName);
			promptLine("nickname> ", nickname);
			promptLine("phone> ", phone);
			promptLine("darkestSecret> ", darkestSecret);

			Contact contact(firstName, lastName, nickname, phone, darkestSecret);
			pb.add(contact);
		}

		else if (cmd == "SEARCH") {
			pb.list();
			PhoneBook::size_type contactId;
			string line;
			
			// Contact ID can't be made of more than 1 digit because the phonebook only supports a maximum of 8 contacts.
			// An entire line is read each time, in order to avoid flushing the buffer each time.
			// Prompt is redisplayed until a valid input (that is, a single digit) is entered.

			do {
				cout << "Contact ID (0-7)> ";
			}
			while(getline(cin, line) && (line.size() != 1 || !isdigit(line[0])));

			if (cin) {
				contactId = line[0] - 48;
				try {
					Contact const *cp = pb.get(contactId);
					
					cout << *cp << endl;
				} catch(out_of_range err) {
					cerr << err.what() << endl;
				}
			}
		}

		else if (cmd == "EXIT") {
			break ;
		}

		else {
			cerr << "\033[1;31mError\033[0m: Unknown command \"" << cmd << "\". Type HELP for help." << endl;
		}
	}

	cout << "Bye!" << endl;
	
	return 0;
}
