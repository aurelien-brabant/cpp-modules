#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
	Cure(Cure const& rhs);
	Cure &operator=(Cure const& rhs);

	public:
		Cure(void);
		~Cure(void);

		Cure* clone(void) const;
		void use(ICharacter & target);
};

#endif
