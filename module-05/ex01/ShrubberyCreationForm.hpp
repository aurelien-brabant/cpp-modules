#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm(std::string const & target = "default_target");
		ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
		
		void executeAction(void);	
};

#endif
