#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;

using std::string;

using std::ostringstream;

int main(int argc, char *argv[])
{
	(void)argc;
	
	// default message if no argument is specified
	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0;
	}

	// using a ostringstream to join program arguments
	ostringstream	oss;
	while (*(++argv)) {
		oss << *argv;
	}

	// get the built string and make it uppercase
	string s(oss.str());
	for (string::iterator it = s.begin(); it != s.end(); ++it) {
		*it = toupper(*it);
	}

	cout << s << endl;

	return 0;
}
