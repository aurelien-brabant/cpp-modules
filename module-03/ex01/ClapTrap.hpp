#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <string>

class ClapTrap {
	protected:
		std::string _name;
		unsigned _hit_points, _energy_points, _attack_damage;

	public:
		ClapTrap(std::string const& name = "0x00");

		ClapTrap(ClapTrap const& ct);

		ClapTrap &operator=(ClapTrap const& cp);

		std::string const	&getName(void) const;
		void				setName(std::string const &name);	

		virtual	~ClapTrap(void);

		virtual void	attack(std::string const& target) const;
		void			takeDamage(unsigned int amount) const;
		void			beRepaired(unsigned int amount) const;
};

#endif
