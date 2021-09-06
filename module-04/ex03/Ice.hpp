#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice(void);
		Ice(Ice const& rhs);
		Ice &operator=(Ice const& rhs);

		Ice* clone(void) const;
};

#endif
