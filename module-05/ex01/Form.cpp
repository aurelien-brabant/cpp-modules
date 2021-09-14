#include "Form.hpp"
#include "Bureaucrat.hpp"

using std::string;
using std::ostream;

Form::Form(string const &name, unsigned execGrade, unsigned signGrade)
	throw(GradeTooLowException, GradeTooHighException)
	: _name(name), _execGrade(execGrade), _signGrade(signGrade)
{
	_validateGradeOrThrow(_execGrade);
	_validateGradeOrThrow(_signGrade);
}

Form::Form(Form const & rhs)
{
	*this = rhs;
}

Form::~Form(void)
{
}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs) {
		_name = rhs._name;
		_execGrade = rhs._execGrade;
		_signGrade = rhs._signGrade;
	}
	return *this;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;	
}

string const & Form::getName(void) const
{
	return _name;
}

unsigned Form::getExecGrade(void) const
{
	return _execGrade;
}

unsigned Form::getSignGrade(void) const
{
	return _signGrade;
}

void Form::_validateGradeOrThrow(unsigned grade)
	throw(GradeTooLowException, GradeTooHighException)
{
	if (grade < 1) {
		throw GradeTooHighException();	
	}

	if (grade > 150) {
		throw GradeTooLowException();
	}
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > getSignGrade()) {
		throw Form::GradeTooLowException();
	}
	_isSigned = true;
}

ostream & operator<<(ostream & os, Form const & rhs)
{
	return (os << rhs.getName() << (rhs.getIsSigned() ? " <signed>" : "") << " (sign: " << rhs.getSignGrade() << ", exec: " << rhs.getExecGrade() << ")");
}

// Form::GradeTooLowException

Form::GradeTooLowException::GradeTooLowException(void)
{
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & rhs)
{
	(void)rhs;
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	(void)rhs;
	return *this;
}

char const * Form::GradeTooLowException::what(void) const throw()
{
	return "Form: grade too low";
}

// Form::GradeTooHighException

Form::GradeTooHighException::GradeTooHighException(void)
{
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & rhs)
{
	(void)rhs;
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	(void)rhs;
	return *this;
}

char const * Form::GradeTooHighException::what(void) const throw()
{
	return "Form: grade too high";
}
