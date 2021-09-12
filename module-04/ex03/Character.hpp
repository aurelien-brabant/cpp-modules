#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	static const int _inventory_size = 4;
	
	std::string _name;
	AMateria* _materia[_inventory_size];

	// Ensures that item at emplacement idx of player's inventory is a valid materia.
	bool isValidMateria(int idx);

	public:
		Character(std::string const & name = "default");
		Character(Character const & rhs);
		~Character(void);

		Character & operator=(Character const & rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void printDebug(void);
};

#endif
