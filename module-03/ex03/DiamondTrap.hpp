#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

/* We're avoiding diamond problem since FragTrap and ScavTrap now both inherits virtually from ClapTrap */

class DiamondTrap: public FragTrap, public ScavTrap {
	std::string _name;

	public:
		DiamondTrap(std::string const& = "DIAMOND-0x00");

		void	whoAmI(void) const;
};

#endif
