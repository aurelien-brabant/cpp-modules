#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria {
	Ice(Ice const& rhs);
	Ice &operator=(Ice const& rhs);

	public:
		Ice(void);
		~Ice(void);

		Ice* clone(void) const;
		void use(ICharacter & target);
};

#endif
