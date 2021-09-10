#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	static const size_t _inventory_size = 4;
	
	std::string _name;
	AMateria* _materia[_inventory_size];

	public:
		Character(std::string const & name = "default");
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
