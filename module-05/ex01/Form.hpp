#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	std::string _name;	
	bool _isSigned;
	unsigned _execGrade;
	unsigned _signGrade;

	public:

		// Bureaucrat exceptions

		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & rhs);
				
				GradeTooHighException & operator=(GradeTooHighException const & rhs);
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & rhs);
				
				GradeTooLowException & operator=(GradeTooLowException const & rhs);
				const char *what() const throw();
		};
		
		unsigned getExecGrade(void) const;
		unsigned getSignGrade(void) const;
		std::string const & getName(void) const;

		void beSigned(Bureaucrat const & signatory);

		Form(std::string const & name = "unnamed", unsigned execGrade = 1, unsigned signGrade = 1);
		Form(Form const & rhs);
		
		Form & operator=(Form const & rhs);
};

std::ostream & operator<<(std::ostream & os, Form const & rhs);

#endif
