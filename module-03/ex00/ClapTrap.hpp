#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>

class ClapTrap {
	std::string _name;
	unsigned _hit_points, _energy_points, _attack_damage;

	public:
		ClapTrap(std::string const& name = "0x00");

		ClapTrap(ClapTrap const& ct);

		ClapTrap &operator=(ClapTrap const& cp);

		std::string const	&getName(void);
		void				setName(std::string const &name);	

		~ClapTrap(void);

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
