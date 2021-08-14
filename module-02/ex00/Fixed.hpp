#ifndef FIXED_HPP
# define FIXED_HPP

// TODO: overload assignation operator

class Fixed {
	private:
		static const unsigned _fbNb = 8;
		int _fixed;
	
	public:
		Fixed(void);
		Fixed(Fixed &);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed	&operator=(Fixed &rhs);
};

#endif
