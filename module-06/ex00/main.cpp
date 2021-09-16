#include <iostream>
#include "ScalarConverter.hpp"
#include <string>
#include <cstdlib>

using std::cerr;
using std::cout;

double ft_stod(std::string const & s);
float ft_stof(std::string const & s);

int main(int argc, char **argv)
{
	if (argc != 2) {
		cerr << "Usage: ./scalcv <literal>\n";
		return 1;
	}

	union {
		double	d;
		float	f;
		char	c;
		int		i;
	} litval;

	ScalarConverter scalcv;

	ScalarConverter::ScalarType type = scalcv.detectType(argv[1]);

	switch (type)
	{
		case ScalarConverter::CHAR_LIT:
			litval.c = argv[1][0];
			scalcv.printConversion(litval.c);
			break ;

		case ScalarConverter::INT_LIT:
			litval.i = atoi(argv[1]);
			scalcv.printConversion(litval.i);
			break ;

		case ScalarConverter::FLOAT_LIT:
			litval.f = ft_stof(argv[1]);
			scalcv.printConversion(litval.f);
			break ;

		case ScalarConverter::DOUBLE_LIT:
			litval.d = ft_stod(argv[1]);
			scalcv.printConversion(litval.d);
			break ;

		case ScalarConverter::FLOAT_PLIT:

		case ScalarConverter::DOUBLE_PLIT:
			scalcv.printPseudoConversion(argv[1], type);
			break ;

		default:
			cerr << "Error: unknown literal\n";
			break ; // just in CASE lol
	}

	return 0;
}
