#include <string>
#include "Weapon.hpp"

class HumanB {
	std::string const _name;
	Weapon const *_weapon;

	public:
		void attack(void);
		void setWeapon(Weapon const& weapon);

		// no default constructor, it is said that HumanB must always have a weapon
		HumanB(std::string const& name);
};
