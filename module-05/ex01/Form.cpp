#include "Form.hpp"

using std::string;

Form::Form(string const &name, unsigned execGrade, unsigned signGrade)
	: _name(name), _execGrade(execGrade), _signGrade(signGrade)
{
}

Form::Form(Form const & rhs)
{
	*this = rhs;
}

Form & Form::operator=(Form const & rhs)
{
	if (this == &rhs) {
		_name = rhs._name;
		_execGrade = rhs._execGrade;
		_signGrade = rhs._signGrade;
	}
	return *this;
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

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() < getSignGrade()) {
		throw GradeTooLowException();
	}
	_isSigned = true;
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
	return "Form: grade too low";
}
