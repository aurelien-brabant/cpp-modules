#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

// TODO: overload assignation operator

class Fixed {
	private:
		static const unsigned _fbNb = 8;
		int _fixed;
	
	public:
		Fixed(void);
		Fixed(Fixed const &);
		Fixed(int const);
		Fixed(float const);
		~Fixed(void);

		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed	&operator=(Fixed const &rhs);
};

std::ostream	&operator<<(std::ostream &lhs, Fixed const &rhs);

#endif
