#include <cctype>
#include "ScalarConverter.hpp"

using std::string;

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & rhs)
{
	(void) rhs;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
	(void) rhs;
	
	return *this;
}

bool ScalarConverter::isChar(std::string const & literal) const
{
	return literal.size() == 1 && !isdigit(literal[0]);
}

bool ScalarConverter::isInt(std::string const & literal) const
{
	for (size_t i = 0; i != literal.size(); ++i) {
		if (!isdigit(literal[i])) {
			return false;
		}
	}
	
	return true;
}

bool ScalarConverter::isFloat(string const & literal) const
{
	bool pointFlag = false;

	// accepted pseudo literals
	if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
		return true;
	}

	// for float, 'f' must always be the last character
	if (literal[literal.size() - 1] != 'f') {
		return false;
	}

	for (size_t i = 0; i != literal.size() - 1; ++i) {
		if (!isdigit(literal[i])) {
			if (literal[i] == '.' && !pointFlag && (i != 0 || i != literal.size() - 1)) {
				pointFlag = true;
				continue ;
			}
			return false;
		}
	}
	
	return true;
}

bool ScalarConverter::isDouble(string const & literal)
{
	bool pointFlag = false;

	// accepted pseudo literals
	if (literal == "+inf" || literal == "-inf" || literal == "nan") {
		return true;
	}

	for (size_t i = 0; i != literal.size() - 1; ++i) {
		if (!isdigit(literal[i])) {
			if (literal[i] == '.' && !pointFlag && (i != 0 || i != literal.size() - 1)) {
				pointFlag = true;
				continue ;
			}
			return false;
		}
	}
	
	return true;
}

ScalarConverter::ScalarType ScalarConverter::detectType(string const & literal) const
{
	typedef bool (ScalarConverter::*LiteralIdentifier)(string const &) const;

	static const LiteralIdentifier identifiers[] = {
		&ScalarConverter::isChar,
		&ScalarConverter::isInt,
		&ScalarConverter::isFloat
	};

	size_t identifierNb = sizeof (identifiers) / sizeof (LiteralIdentifier);

	for (size_t i = 0; i != identifierNb; ++i) {
		if ((this->*identifiers[i])(literal)) {
			return static_cast<ScalarType>(i);
		}
	}

	return UNIDENTIFIED_LITERAL;
}
