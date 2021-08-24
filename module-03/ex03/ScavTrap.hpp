#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

/* About virtual inheritance: https://en.wikipedia.org/wiki/Virtual_inheritance */

class ScavTrap: virtual public ClapTrap {
	public:
		ScavTrap(std::string const& name = "0x00");

		~ScavTrap(void);
		
		void	attack(const std::string &target) const;
		void	guardGate(void) const;
};

#endif
