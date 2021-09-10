#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria {
	public:
		Cure(void);
		Cure(Cure const& rhs);
		Cure &operator=(Cure const& rhs);

		Cure* clone(void) const;
		void use(ICharacter & target);
};

#endif
