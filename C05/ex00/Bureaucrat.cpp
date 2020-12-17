/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:27:33 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/17 12:26:43 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& copyObj) :
	_name(copyObj._name), _grade(copyObj._grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(Bureaucrat& a, Bureaucrat& b)
{
	std::swap(a._grade, b._grade);
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}
void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& output, Bureaucrat& brct)
{
	output << brct.getName() << ", bureaucrat grade " << brct.getGrade() << ".\n";
	return (output);
}


// Exception : GradeTooHigh

Bureaucrat::GradeTooHighException::GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (max grade : 1)\n");
}


// Exception : GradeTooLow

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (max grade : 150)\n");
}