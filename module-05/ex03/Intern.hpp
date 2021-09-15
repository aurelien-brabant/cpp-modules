#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	// Form allocators
	
	Form * allocateRobotomyRequestForm(std::string const & target) const;
	Form * allocatePresidentialPardonForm(std::string const & target) const;
	Form * allocateShrubberyCreationForm(std::string const & target) const;

	struct FormTypeEntry {
		std::string formType;
		Form * (Intern::*formAllocator)(std::string const & name) const;
	};	

	static const FormTypeEntry formEntries[];

	// Because Intern does not have any distinctive attribute, copy or assignment makes no sense.
	// That's the reason why they are "deleted" (using C++98 constraints).
	// That's a personal choice.
	Intern(Intern const & rhs);
	
	Intern & operator=(Intern const & rhs);
	

	public:
		Intern(void);
		~Intern(void);

		Form * makeForm(std::string const & formType, std::string const & target) const;
};

#endif
