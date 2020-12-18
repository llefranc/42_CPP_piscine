/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:32:31 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/17 17:40:42 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:

		ShrubberyCreationForm(const std::string& target = "home");
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm& copyObj);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm assignObj);
		friend void swap(ShrubberyCreationForm& a, ShrubberyCreationForm& b);
		
		const std::string& getTarget() const;
		
		void shrubberyCreation() const;
		virtual void execute(const Bureaucrat& executor) const;
	
	private:

		std::string	_target;
};

#endif