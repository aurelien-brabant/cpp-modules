#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM
# include <string>
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
	std::string _target;

	public:
		RobotomyRequestForm(std::string const & target = "default");
		RobotomyRequestForm(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm(void);
		
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
		
		void executeAction(void) const;
};

#endif
