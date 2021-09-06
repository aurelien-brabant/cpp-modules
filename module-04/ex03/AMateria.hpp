#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(std::string const& type);
		
		std::string const& getType(void) const;

		virtual AMateria *clone(void) const = 0;
	//	virtual void use(void);
};

#endif
