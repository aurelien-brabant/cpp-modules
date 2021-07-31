#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "replace.h"

using std::ofstream; using std::ifstream;
using std::cerr; using std::endl; using std::getline; using std::cout;
using std::string;
using std::nothrow;

static const char *replaceExt = "replace";

// build replace filename using C string manipulation as C++98 fstreams do not accept std::string constructors

static char *buildReplacedFilename(char const *filename)
{
	char const *basenamedFilename = strrchr(filename, '/');
	if (basenamedFilename) {
		filename = basenamedFilename + 1; // skip last slash
	}

	char *replacedFilename = new (nothrow) char[strlen(filename) + strlen(replaceExt) + 2]; // room for dot and null

	if (!replacedFilename) return 0;

	strcpy(replacedFilename, filename);
	strcat(replacedFilename, ".");
	strcat(replacedFilename, replaceExt);

	return replacedFilename; 
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		cerr << "Usage: replace <file> <replaced char sequence> <replacement char sequence>" << endl;
		return ERROR_BAD_USAGE;
	}

	if (!argv[1][0] || !argv[2][0] || !argv[3][0]) {
		cerr << "Can't process an empty string" << endl;
		return ERROR_EMPTY_STRING;
	}

	ifstream ifs(argv[1]);
	
	if (!ifs) {
		cerr << "Could not open file \"" << argv[1] << "\" for reading" << endl;
		return ERROR_FSTREAM;
	}

	const char *replacedFilename = buildReplacedFilename(argv[1]);

	if (!replacedFilename) {
		cerr << "Could not allocate replaceFilename" << endl;
		return ERROR_BAD_ALLOC;
	}

	ofstream ofs(replacedFilename);
	delete[] replacedFilename;

	if (!ofs) {
		cerr << "Could not open replaced file for writing" << endl;
		return ERROR_FSTREAM;
	}

	// Process each line individually, manually replacing each occurence of the first
	// string by the second one. It is done in a smart (I think) fashion to avoid
	// write operation as much as possible.
	
	size_t s1Len = strlen(argv[2]), count = 0;

	string line;
	while (getline(ifs, line)) {
		for (size_t i = 0; i < line.size(); ++i) {
			size_t foundAt = line.find(argv[2], i);

			if (foundAt != string::npos) {
				++count;
				if (foundAt > i) {
					string sub = line.substr(i, foundAt - i);
					ofs << sub;
					i += sub.size();
				}
				ofs << argv[3];
				i += s1Len - 1;
			} else {
				// if no occurence is found, write the remaining of the line and process the next line
				ofs << &line[i];
				break ;
			}
		}
		if (!ifs.eof()) {
			ofs << "\n";
		}
	}

	cout << count << endl;
	
	return 0;
}
