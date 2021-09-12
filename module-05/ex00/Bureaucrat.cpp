#include "Bureaucrat.hpp"

using std::endl;

Bureaucrat::Bureaucrat(std::string const &name, unsigned grade)
	throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
	: _name(name), _grade(grade)
{
	_validateGradeOrThrow(_grade);
}

void Bureaucrat::_validateGradeOrThrow(unsigned grade) throw(...)
{
	if (grade < 1) throw "grade too low exception";
	if (grade > 150) throw "grade too high exception";
}

unsigned Bureaucrat::getGrade(void) const
{
	return _grade;
}

std::string const & Bureaucrat::getName(void) const
{
	return _name;
}

void Bureaucrat::promote(void) throw(Bureaucrat::GradeTooHighException)
{
	_validateGradeOrThrow(_grade++);
}

void Bureaucrat::demote(void) throw(Bureaucrat::GradeTooLowException)
{
	_validateGradeOrThrow(_grade--);
}

std::ostream &operator<<(std::ostream & os, Bureaucrat const &rhs)
{
	return (os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << endl);
}

// Bureaucrat::GradeTooHighException

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat::GradeTooHighException const & rhs)
{
	*this = rhs;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const & rhs)
{
	(void)rhs;
	return *this;
}

char const * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

// Bureaucrat::GradeTooLowException

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const & rhs)
{
	*this = rhs;
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const & rhs)
{
	(void)rhs;
	return *this;
}

char const * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}
