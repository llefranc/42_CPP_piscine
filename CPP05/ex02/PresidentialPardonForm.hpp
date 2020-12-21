/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:32:31 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/17 17:40:54 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:

		PresidentialPardonForm(const std::string& target = "home");
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm(const PresidentialPardonForm& copyObj);
		PresidentialPardonForm& operator=(PresidentialPardonForm assignObj);
		friend void swap(PresidentialPardonForm& a, PresidentialPardonForm& b);
		
		const std::string& getTarget() const;
		
		void presidentialPardon() const;
		virtual void execute(const Bureaucrat& executor) const;
	
	private:

		std::string	_target;
};

#endif