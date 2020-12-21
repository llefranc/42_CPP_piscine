/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:32:47 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/17 16:24:47 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	Form("PresidentialPardonForm", 25, 5), _target(target) {}
	
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copyObj) :
	Form(copyObj) {}
	
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(PresidentialPardonForm& a, PresidentialPardonForm& b)
{
	swap(dynamic_cast<Form&>(a), dynamic_cast<Form&>(b));
	std::swap(a._target, b._target);
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::presidentialPardon() const
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox\n";
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	Form::checkAuthorizations(executor);
	presidentialPardon();
}