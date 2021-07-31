#ifndef WEAPON_H
# define WEAPON_H
# include <string>

class Weapon {
	std::string _type;
	
	public:	
		void setType(std::string const &type);
		std::string const &getType(void) const;

		Weapon(std::string const &type = "sword");
};

#endif
