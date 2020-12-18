/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:32:31 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/18 11:03:30 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <math.h>

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:

		RobotomyRequestForm(const std::string& target = "home");
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm& copyObj);
		RobotomyRequestForm& operator=(RobotomyRequestForm assignObj);
		friend void swap(RobotomyRequestForm& a, RobotomyRequestForm& b);
		
		const std::string& getTarget() const;
		
		void robotomyRequest() const;
		virtual void execute(const Bureaucrat& executor) const;
		
	private:

		std::string	_target;
};

#endif