#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include "ClapTrap.hpp"

/* About virtual inheritance: https://en.wikipedia.org/wiki/Virtual_inheritance */

class FragTrap: virtual public ClapTrap {
	public:
		FragTrap(std::string const& name = "0x00");
		FragTrap(FragTrap const &ft);

		FragTrap& operator=(FragTrap const &rhs);

		~FragTrap(void);
		
		void	highFiveGuys(void) const;
};

#endif
