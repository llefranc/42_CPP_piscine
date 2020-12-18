/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaslefrancq <lucaslefrancq@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:30:19 by lucaslefran       #+#    #+#             */
/*   Updated: 2020/12/18 10:26:29 by lucaslefran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:

		class NoMatch : public std::exception
		{
			public:
			
				NoMatch() throw();
				virtual const char* what() const throw();
		};

		Intern();
		~Intern();
		Intern(const Intern& copyObj);
		Intern& operator=(const Intern& assignObj);
		
		Form* makeForm(std::string formType, std::string target);

		static Form* makeRRForm(std::string& target);
		static Form* makeSCForm(std::string& target);
		static Form* makePPForm(std::string& target);

	private:
	
		std::string _formsArray[3];
		Form* (*_make[3])(std::string& target);
};

#endif