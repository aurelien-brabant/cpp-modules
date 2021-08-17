#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <stdint.h>

// TODO: overload assignation operator

class Fixed {
	private:
		static const unsigned _fbNb = 8;
		int32_t _fixed;
	
	public:
		Fixed(void);
		Fixed(Fixed const &);
		Fixed(int const);
		Fixed(float const);
		~Fixed(void);

		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed const &min(Fixed const &f1, Fixed const &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static Fixed const &max(Fixed const &f1, Fixed const &f2);

		static unsigned getNbOfFractionalBits(void);

		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed	&operator=(Fixed const &rhs);
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
};

std::ostream	&operator<<(std::ostream &lhs, Fixed const &rhs);

bool			operator==(Fixed const &lhs, Fixed const &rhs);
bool			operator>=(Fixed const &lhs, Fixed const &rhs);
bool			operator>=(Fixed const &lhs, Fixed const &rhs);
bool			operator>=(Fixed const &lhs, Fixed const &rhs);
bool			operator<=(Fixed const &lhs, Fixed const &rhs);
bool			operator>(Fixed const &lhs, Fixed const &rhs);
bool			operator<(Fixed const &lhs, Fixed const &rhs);
bool			operator!=(Fixed const &lhs, Fixed const &rhs);

Fixed			operator+(Fixed const &lhs, Fixed const &rhs);
Fixed			operator-(Fixed const &lhs, Fixed const &rhs);
Fixed			operator/(Fixed const &lhs, Fixed const &rhs);
Fixed			operator*(Fixed const &lhs, Fixed const &rhs);

#endif
