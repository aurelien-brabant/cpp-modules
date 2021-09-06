#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

struct Brain
{
	static size_t const idea_nb = 100;

	std::string ideas[idea_nb];
	Brain();
	Brain(Brain const& rhs);
	~Brain();

	Brain& operator=(Brain const& rhs);
	std::string const &getIdea(size_t index) const;
	void setIdea(size_t index, std::string const &s);
};

#endif
