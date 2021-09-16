#include <cctype>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "ScalarConverter.hpp"

using std::string;
using std::cout;
using std::left; using std::setw;

static std::ostream & printFloat(std::ostream & os, float f)
{
	os << f;
	if (f == roundf(f)) {
		os << ".0";
	}
	os << "f";
	
	return os;
}

static std::ostream & printDouble(std::ostream & os, float f)
{
	os << f;
	if (f == roundf(f)) {
		os << ".0";
	}
	
	return os;
}

static std::ostream & printChar(std::ostream & os, char c)
{
	if (isprint(c)) {
		os << "'" << c << "'";
	} else {
		os << "Non displayable";
	}
	
	return os;
}

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

// Detect pseudo-literals

bool ScalarConverter::isPseudoFloat(string const & s) const
{
	return (
		s == "nanf" ||
		s == "+inff" ||
		s == "-inff"
	);
}

bool ScalarConverter::isPseudoDouble(string const & s) const
{
	return (
		s == "nan" ||
		s == "+inf" ||
		s == "-inf"
	);
}

ScalarConverter::ScalarType ScalarConverter::detectType(string const & literal) const
{
	bool floatingPoint = false;

	if (literal.size() == 1 && !isdigit(literal[0])) {
		return CHAR_LIT;
	}

	if (isPseudoDouble(literal)) return DOUBLE_PLIT;
	if (isPseudoFloat(literal)) return FLOAT_PLIT;

	for (size_t i = 0; i != literal.size(); ++i) {
		if (!isdigit(literal[i])) {
			if ((literal[i] == '-' || literal[i] == '+') && i == 0) {
				continue ;
			}
			else if (literal[i] == 'f' && i == literal.size() - 1) {
				return FLOAT_LIT;
			}
			else if (literal[i] == '.' && !floatingPoint && (i != 0 && i != literal.size() - 1))	{
				floatingPoint = true;
				continue ;
			}
			return UNDEF_LIT;
		}
	}
	
	return floatingPoint ? DOUBLE_LIT : INT_LIT;
}


void ScalarConverter::printConversion(char c) const
{
	cout << left;

	cout << setw(10) << "* char: ";
	printChar(cout, c) << "\n";

	cout << setw(10) << "int: " << static_cast<int>(c) << "\n";

	cout << setw(10) << "float: ";
	printFloat(cout, static_cast<float>(c)) << "\n";

	cout << setw(10) << "double: ";
	printDouble(cout, static_cast<double>(c)) << "\n";
}

void ScalarConverter::printConversion(float f) const
{
	cout << left;
	cout << setw(10) << "char: ";
	printChar(cout, static_cast<char>(f)) << "\n";
	
	cout << setw(10) << "int: " << static_cast<int>(f) << "\n";

	cout << setw(10) << "* float: ";
	printFloat(cout, f) << "\n";

	cout << setw(10) << "double: ";
	printDouble(cout, static_cast<double>(f)) << "\n";
}

void ScalarConverter::printConversion(int i) const
{
	cout << left;

	cout << setw(10) << "char: ";
	printChar(cout, static_cast<char>(i)) << "\n";
	
	cout << setw(10) << "* int: " << i << "\n";

	cout << setw(10) << "float: ";
	printFloat(cout, static_cast<float>(i)) << "\n";

	cout << setw(10) << "double: ";
	printDouble(cout, static_cast<double>(i)) << "\n";
}

void ScalarConverter::printConversion(double d) const
{
	cout << left;

	cout << setw(10) << "char: ";
	printChar(cout, static_cast<char>(d)) << "\n";
	
	cout << setw(10) << "int: " << static_cast<int>(d) << "\n";

	cout << setw(10) << "float: ";
	printFloat(cout, static_cast<float>(d)) << "\n";

	cout << setw(10) << "* double: ";
	printDouble(cout, d) << "\n";
}

void ScalarConverter::printPseudoConversion(std::string const & pseudo_literal, ScalarType type)
{
	cout << left;

	cout << setw(10) << "char: " << "impossible\n";

	cout << setw(10) << "int: " << "impossible\n";

	cout << setw(10) << ((type == FLOAT_PLIT ? string("* ") : string("")) + "float: ") << (type == DOUBLE_PLIT ? (pseudo_literal + "f") : pseudo_literal) << "\n";
	
	cout << setw(10) << ((type == DOUBLE_PLIT ? string("* ") : string()) + "double: ") << (type == FLOAT_PLIT ? (string(pseudo_literal).erase(pseudo_literal.size() - 1, 1)) : pseudo_literal) << "\n";
}
