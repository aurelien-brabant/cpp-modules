#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(std::string const& name = "0x00");

		~FragTrap(void);
		
		void	highFiveGuys(void) const;
};

#endif
