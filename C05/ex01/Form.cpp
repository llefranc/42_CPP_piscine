/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:58:17 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/18 10:52:13 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Coplien form : constructor, destructor, copyconstructor and assignment operator= */

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToExecute < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& copyObj) :
	_name(copyObj._name), _isSigned(copyObj._isSigned), _gradeToSign(copyObj._gradeToSign),
	_gradeToExecute(copyObj._gradeToExecute) {}
	
Form& Form::operator=(Form assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(Form& a, Form& b)
{
	std::swap(a._isSigned, b._isSigned);
}


/* Get functions */

const std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}


/* Methods */

void Form::beSigned(Bureaucrat& brct)
{
	if (_isSigned)
	{
		std::cout << "This form is already signed!\n";
		return ;
	}

	if (brct.getGrade() <= _gradeToSign)
		brct.signForm(_gradeToSign, _name);
	else
	{
		brct.signForm(_gradeToSign, _name);
		throw GradeTooLowException();
	}
}


/* Operator overloads */

std::ostream& operator<<(std::ostream& output, Form& form)
{
	std::cout << "Form " << form.getName() << ": required grade " << form.getGradeToSign()
		<< " to be signed and grade " << form.getGradeToExecute() << " to be executed. This form";
	if (form.getIsSigned())
		std::cout << " is already signed.\n";
	else
		std::cout << " isn't signed for the moment\n";
	return (output);
}


/* Exceptions */

// Exception class GradeTooHigh

Form::GradeTooHighException::GradeTooHighException() throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high\n");
}


// Exception class GradeTooHigh

Form::GradeTooLowException::GradeTooLowException() throw() {}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low\n");
}