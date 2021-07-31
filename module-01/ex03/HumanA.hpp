#include <string>
#include "Weapon.hpp"

class HumanA {
	std::string const _name;
	Weapon const& _weapon;

	public:
		void attack(void);

		// no default constructor, it is said that HumanA must always have a weapon
		HumanA(std::string const& name, Weapon const& weapon);
};
