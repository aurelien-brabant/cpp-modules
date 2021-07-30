#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <string>

class Zombie {
	std::string _name;

	public:
		// also acts as a default constructor, because name can be omitted.
		Zombie(std::string const &name = "Unknown zombie");
		~Zombie(void);

		void setName(std::string const &name);
		void announce(void) const;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
