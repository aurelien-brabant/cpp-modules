#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM
# include <string>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

		void executeAction(void) const;
};

#endif
