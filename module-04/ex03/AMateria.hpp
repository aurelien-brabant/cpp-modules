#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class AMateria
{
	AMateria(AMateria const & rhs);
	AMateria & operator=(AMateria const & rhs);

	protected:
		std::string _type;

	public:
		AMateria(std::string const & type);
		virtual ~AMateria(void);

		std::string const& getType(void) const;
		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter & target);
};

#endif
