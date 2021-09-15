#include "Form.hpp"
#include "Bureaucrat.hpp"

using std::string;
using std::ostream;

Form::Form(string const &name, unsigned execGrade, unsigned signGrade)
	throw(GradeTooLowException, GradeTooHighException)
	: _name(name), _isSigned(false), _execGrade(execGrade), _signGrade(signGrade)
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

void Form::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned()) {
		throw ExecNotSignedException();
	}

	if (executor.getGrade() > getExecGrade()) {
		throw GradeTooLowException();
	}
	executeAction();
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

// Form::ExecNotSignedException

Form::ExecNotSignedException::ExecNotSignedException(void)
{
}

Form::ExecNotSignedException::ExecNotSignedException(ExecNotSignedException const & rhs)
{
	(void)rhs;
}

Form::ExecNotSignedException & Form::ExecNotSignedException::operator=(ExecNotSignedException const & rhs)
{
	(void)rhs;
	return *this;
}

char const * Form::ExecNotSignedException::what(void) const throw()
{
	return "Form: cannot execute a form which is not signed";
}
