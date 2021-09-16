#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <string>

class ScalarConverter
{
	bool isPseudoFloat(std::string const & s) const;
	bool isPseudoDouble(std::string const &s) const;

	public:
		enum ScalarType { UNDEF_LIT = -1, CHAR_LIT = 0, INT_LIT, FLOAT_LIT, DOUBLE_LIT, FLOAT_PLIT, DOUBLE_PLIT, TOTAL_LIT };

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & rhs);
		
		ScalarConverter & operator=(ScalarConverter const & rhs);

		ScalarType detectType(std::string const & literal) const;
		
		void printConversion(char c) const;
		void printConversion(int i) const;
		void printConversion(double d) const;
		void printConversion(float f) const;
		void printPseudoConversion(std::string const & pseudo_literal, ScalarType type);
};

#endif
