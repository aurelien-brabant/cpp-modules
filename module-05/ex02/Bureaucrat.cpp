#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::exception;
using std::cout; using std::endl;

Bureaucrat::Bureaucrat(std::string const &name, unsigned grade)
	throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
	: _name(name), _grade(grade)
{
	_validateGradeOrThrow(_grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs): _name(rhs._name)
{
	*this = rhs;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs) {
		_grade = rhs._grade;
	}
	return *this;
}

void Bureaucrat::_validateGradeOrThrow(unsigned grade)
		throw(GradeTooLowException, GradeTooHighException)
{
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
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
	_validateGradeOrThrow(_grade - 1);
	--_grade;
}

void Bureaucrat::demote(void) throw(Bureaucrat::GradeTooLowException)
{
	_validateGradeOrThrow(_grade + 1);
	++_grade;
}

void Bureaucrat::signForm(Form & form) throw (Form::GradeTooLowException)
{
	try {
		form.beSigned(*this);
		cout << getName() << " signs " << form.getName() << endl;
	} catch(exception & e) {
		cout << getName() << " cannot sign " << form.getName() << " because " << e.what() << endl;	
	}
}

void Bureaucrat::executeForm(Form const & form) const
{
	try {
		form.execute(*this);
		cout << getName() << " executes " << form.getName() << endl;
	} catch(exception & e) {
		cout << getName() << " cannot execute " << form.getName() << " because " << e.what() << endl;	
	}
}

std::ostream &operator<<(std::ostream & os, Bureaucrat const &rhs)
{
	return (os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".");
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
	return "Bureaucrat: Grade too high";
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
	return "Bureaucrat: grade too low";
}
