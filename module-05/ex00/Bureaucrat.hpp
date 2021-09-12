#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <stdexcept>
# include <iostream>

class Bureaucrat
{
	std::string const _name;
	unsigned _grade;

	void _validateGradeOrThrow(unsigned grade) throw(...);

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

		// Constructors
		Bureaucrat(const std::string &name = "Unnamed", unsigned grade = 150)
			throw(GradeTooLowException, GradeTooHighException);
		Bureaucrat(Bureaucrat const & rhs);

		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string const & getName(void) const;
		unsigned getGrade(void) const;
		// exception specification
		void promote(void) throw(GradeTooHighException);
		void demote(void) throw(GradeTooLowException);
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &rhs);

#endif
