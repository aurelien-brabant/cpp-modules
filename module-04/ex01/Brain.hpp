#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

struct Brain
{
	static size_t const idea_nb = 100;

	std::string ideas[idea_nb];
	Brain();
	Brain(Brain const& rhs);
	~Brain();

	Brain& operator=(Brain const& rhs);
};

#endif
