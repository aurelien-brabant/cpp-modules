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

ScalarConverter::ScalarType ScalarConverter::detectType(string const & literal) const
{
	bool floatingPoint = false;

	if (literal.size() == 1 && !isdigit(literal[0])) {
		return CHAR;	
	}

	for (size_t i = 0; i != literal.size(); ++i) {
		if (!isdigit(literal[i])) {
			if ((literal[i] == '-' || literal[i] == '+') && i == 0) {
				continue ;
			}
			else if (literal[i] == 'f' && i == literal.size() - 1) {
				return FLOAT;
			}
			else if (literal[i] == '.' && !floatingPoint && (i != 0 && i != literal.size() - 1))	{
				floatingPoint = true;
				continue ;
			}
			return UNIDENTIFIED_LITERAL;
		}
	}
	
	return floatingPoint ? DOUBLE : INT;
}
