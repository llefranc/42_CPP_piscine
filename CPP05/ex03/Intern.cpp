/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:30:05 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/18 10:26:20 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	_formsArray[0] = "robotomy request";
	_formsArray[1] = "presidential pardon";
	_formsArray[2] = "shrubbery creation";

	// Array of ptr function
	_make[0] = makeRRForm;
	_make[1] = makePPForm;
	_make[2] = makeSCForm;
}

Intern::~Intern() {}

Intern::Intern(const Intern& copyObj) {(void)copyObj;}

Intern& Intern::operator=(const Intern& assignObj)
{
	(void)assignObj;
	return (*this);
}

Form* Intern::makeForm(std::string formType, std::string target)
{
	int i = 0;
	while (i < 3 && formType != _formsArray[i])
		i++;
	if (i == 3)
		throw NoMatch();
	return ((_make[i])(target));
}

// Static methods

Form* Intern::makePPForm(std::string& target)
{
	return (new PresidentialPardonForm(target));
}

Form* Intern::makeSCForm(std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeRRForm(std::string& target)
{
	return (new RobotomyRequestForm(target));
}


// Exceptions

Intern::NoMatch::NoMatch() throw() {}

const char* Intern::NoMatch::what() const throw()
{
	return ("No match for the required form to create\n");
}