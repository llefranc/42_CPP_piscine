/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:32:47 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/17 16:04:51 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	Form("RobotomyRequestForm", 72, 45), _target(target) {}
	
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copyObj) :
	Form(copyObj) {}
	
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm assignObj)
{
	swap(*this, assignObj);
	return (*this);
}

void swap(RobotomyRequestForm& a, RobotomyRequestForm& b)
{
	swap(dynamic_cast<Form&>(a), dynamic_cast<Form&>(b));
	std::swap(a._target, b._target);
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::robotomyRequest() const
{
	if (rand() % 2)
		std::cout << "Dring dring dring! " << _target << " has been succesfully robotomized!\n";
	else
		std::cout << "Robotomization on " << _target << " failed!\n";
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	Form::checkAuthorizations(executor);
	robotomyRequest();
}