#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <string>

class ScalarConverter
{
	bool isFloat(std::string const & literal) const;
	bool isInt(std::string const & literal) const; 
	bool isChar(std::string const & literal) const;
	//bool isDouble(std::string const & literal) const;

	public:
		enum ScalarType { UNIDENTIFIED_LITERAL = -1, CHAR = 0, INT, FLOAT, DOUBLE, TOTAL };

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & rhs);
		
		ScalarConverter & operator=(ScalarConverter const & rhs);

		ScalarType detectType(std::string const & literal) const;
};

#endif
